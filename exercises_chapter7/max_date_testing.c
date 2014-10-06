#include <stdio.h>
#include <stdlib.h>

/* function */
struct Date * max_date(struct Date first_date, struct Date second_date);
struct Date * min_date(struct Date first_date, struct Date second_date);
void date_description(struct Date* given_date);
int date_difference(struct Date first_date, struct Date second_date);
int dayInYear(int day, int month, int year);
int dayInYear_byDate(struct Date given_date);
int isLeapYear(int year);
int leap_day_count(struct Date first_date, struct Date second_date);
void promptUser(char line[], struct Date *current_date);
int is_date_valid(int day, int month, int year);
void format_yearDay(int total_days, int leap_days);
void format_days(int total_days, int leap_days);


/* Date Structure Type Definition */
struct Date {
	int day;
	int month;
	int year;
};

/* Global Vars */
int leap_days = 0;

/* Reserve memory for Struct Dates formed from user input
 * static vars gaurentee that the pointers will not be released from memory 
 */
static struct Date date_1;
static struct Date date_2;

/* User Input */
char line_1[100]; /* user input format: dd/mm/yyyy (10 char) + EOL char (11 char total) */
char line_2[100]; /* user input format: dd/mm/yyyy (10 char) + EOL char (11 char total) */



int main(int argc, char *argv[]) {
	
	/* Testing - Early Stage Hard Coding
	int date_1_day = 6;
	int date_1_month = 1;
	int date_1_year = 1985;
	
	int date_2_day = 14;
	int date_2_month = 11;
	int date_2_year = 2001;
	*/
	
	/* Prompt the User for dates they would like to find the interval between */
	promptUser(line_1, &date_1);
	promptUser(line_2, &date_2);
	
	/* Debugging Pointer testing
	// Pointers
	printf("*date_1: %10p\n", &date_1);
	printf("*date_2: %10p\n", &date_2);
	
	// Values
	printf("date_1.day: %d", date_1.day);
	printf("date_2.day: %d", date_2.day);
	 
	// Date in 'description' ('dd/mm/yyyy') form 
	date_description(&date_1);
	date_description(&date_2);
	*/
	
	/* Store the result of max_date() - a pointer to the latest date - in a pointer of struct Date 
	 * Store the result of min_date() - a pointer to the earliest date - in a pointer of struct Date 
	 */
	struct Date *min_date_ptr = min_date(date_1, date_2);
	struct Date *max_date_ptr = max_date(date_1, date_2);

	
	/* Create structs from min/max_date method results.
	 * These new structs will ensure that the dates are ordered properly for date arithmatic
	 * found in the function: date_difference()
	 */
	struct Date min_date = *min_date_ptr;
	struct Date max_date = *max_date_ptr;

	
	/* 
	// Print the earliest and latest date for testing purposes 
	printf("min_date = ");
	date_description(&min_date);
	
	printf("max_date = ");
	date_description(&max_date);
	*/
	
	/* Calculate the interval between the dates */
	int difference = date_difference(date_1, date_2);
	int leap_days = leap_day_count(date_1, date_2);
	
	/* Format the program output */
	// Difference formatted with the difference in years and days
	format_yearDay(difference, leap_days);
	format_days(difference, leap_days);
	
	
}


/* Functions using Structs as arguments - MUST PROCEED MAIN FUNCTION */
/* Prints a description of the date struct */
void date_description(struct Date* given_date) {
	
	printf("%d/%d/%d\n", given_date->day, given_date->month, given_date->year);
	
}


int date_difference(struct Date first_date, struct Date second_date) {
	
	// Debugging
	//printf("date_difference() called\n");
	
	// Variable to store the total days between the dates
	int total_days = 0;
	
	// Find the Latest and Earliest date
	struct Date *max_date_ptr = max_date(first_date, second_date);
	struct Date *min_date_ptr = min_date(first_date, second_date);
	struct Date max_date = *max_date_ptr;
	struct Date min_date = *min_date_ptr;
	
	// Conditional Variable
	int year_difference = max_date.year - min_date.year;
	
	// Debugging
	//printf("year_difference: %d\n", year_difference);
	
	if (year_difference == 0) {
		
		printf("The difference is simply between the days of the same year.\n");
		
		/* Subtract the dayInYear Value of min_date from max_date */
		total_days = dayInYear_byDate(max_date) - dayInYear_byDate(min_date);
		
	} else {
	
	// Debugging
	//printf("The difference is a year or more apart.\n");
	
		/* The earliest date must find the days remaining in its year */
		int remainingDaysInYear = 365 + isLeapYear(min_date.year) - dayInYear_byDate(min_date);
		
	// Debugging
	//printf("remainingDaysInYear from min_date: %d\n", remainingDaysInYear);
		
		total_days += remainingDaysInYear;
	
		/* NOTE: If the years are equal, the for loop will NOT run. */
		for(int i = min_date.year + 1; i < max_date.year; i++) {
			
			// Debugging
			//printf("The Current Year is: %d\n", i);
			
			if (i > max_date.year) {
				// Then there is less than a year between the dates
				break;
			}
			
			// Add 365 for a full year, 366 if a leap year. isLeapYear() returns 1 if true, else 0
			total_days += 365 + isLeapYear(i);
			
		}
		
		// Add the dayInYear value for the max_date
		total_days += dayInYear_byDate(max_date);
		
		// Debugging
		//printf("daysInYear to max_date: %d\n", dayInYear_byDate(max_date));
	
	}
	
	return total_days;
}





/* Returns the latest of two dates.
 * If the dates are the same, the function returns a pointer to the first date used as an argument.
 *
 * NOTE: The return value MUST be stored in a pointer object to a struct Date:
 *		Ex: 
 *			// Store the result of max_date() - a pointer to the latest date - in a pointer of struct Date
 *			struct Date *max_date_ptr = max_date(date_1, date_2);
 *			
 *			// Use the pointer of struct Date to initialize the struct Date max_date to the returned by the max_date() function
 *			struct Date max_date = *max_date_ptr;
 */
struct Date * max_date(struct Date first_date, struct Date second_date) {
	
	/* A pointer to the latest date */
	struct Date *max_ptr;
	
	if (first_date.year > second_date.year) {
		max_ptr = &first_date;
	} else if (first_date.year < second_date.year) {
		max_ptr = &second_date;
	} else {
		
		// Debugging
		//printf("The years are equal, testing month.\n");
		
		/* The dates are from the same year, check the months */
		if (first_date.month > second_date.month) {
				max_ptr = &first_date;
			} else if (first_date.month < second_date.month) {
				max_ptr = &second_date;
			} else {
				
				// Debugging
				//printf("The years and months are equal, testing day.\n");
				
				/* The dates are from the same month and year, we must check the difference in days */
				if (first_date.day > second_date.day) {
						max_ptr = &first_date;
					} else if (first_date.day < second_date.day) {
						max_ptr = &second_date;
					} else {
						// Debugging
						//printf("The dates are the same, returning the first date argument.\n");
						max_ptr = &first_date;
					}
			}
	}
	
	return max_ptr;
}

/* Returns the latest of two dates.
 * If the dates are the same, the function returns a pointer to the first date used as an argument.
 *
 * NOTE: The return value MUST be stored in a pointer object to a struct Date:
 *		Ex: 
 *			// Store the result of max_date() - a pointer to the latest date - in a pointer of struct Date
 *			struct Date *max_date_ptr = max_date(date_1, date_2);
 *			
 *			// Use the pointer of struct Date to initialize the struct Date max_date to the returned by the max_date() function
 *			struct Date max_date = *max_date_ptr;
 */
struct Date * min_date(struct Date first_date, struct Date second_date) {
	
	/* A pointer to the latest date */
	struct Date *min_ptr;
	
	if (first_date.year < second_date.year) {
		min_ptr = &first_date;
	} else if (first_date.year > second_date.year) {
		min_ptr = &second_date;
	} else {
		
		// Debugging
		//printf("The years are equal, testing month.\n");
		
		/* The dates are from the same year, check the months */
		if (first_date.month < second_date.month) {
				min_ptr = &first_date;
			} else if (first_date.month > second_date.month) {
				min_ptr = &second_date;
			} else {
				
				// Debugging
				//printf("The years and months are equal, testing day.\n");
				
				/* The dates are from the same month and year, we must check the difference in days */
				if (first_date.day < second_date.day) {
						min_ptr = &first_date;
					} else if (first_date.day > second_date.day) {
						min_ptr = &second_date;
					} else {
						// Debugging
						//printf("The dates are the same, returning the first date argument.\n");
						min_ptr = &first_date;
					}
			}
	}
	
	return min_ptr;
}



/* Returns the integer value for the supplied date out of 365 or 366 if the date falls within a leap year  */
int dayInYear (int day, int month, int year) {
	
	/* Variable for the integer value of the day in the year */
	int dayInYear = 0;
	
	/* Rules for a year */
	/* If the year is a leap year, the leap day is added if necessary in the date_difference() function */
		
	/* Loop through switch statement to determine how many days to add to the year for each month. */
	for(int i = 1; i < month; i++) {
	
		/* If the i is the current month, break out of the loop (add the value of the day of that month) */
		if (i == month) {
			break;
		}
	
		switch (i) {
			/* Add 31 days for Jan, March, May, July, Aug, Oct and Dec */
					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
						dayInYear += 31;
						break;
			/* Add 30 days for Apr, June, Sept, and Nov */
					case 4:
					case 6:
					case 9:
					case 11:
						dayInYear += 30;
						break;
			
			/* Exception Cases */		
			/* Add 28 days for Feb, this code handles leap years */
					case 2:
						dayInYear += 28 + isLeapYear(year);
						break;
			/* The Last month of the year only adds the days */
					case 12:
						break;
						
					default:
					printf("The provided month is not does not exist on the Gregorian Calendar");
						break;
				}	
	}
		
	/* Add the remaining days of the final month */
	dayInYear += day;	
		
	return dayInYear;
}



/* This method calls dayInYear (int day, int month, int year) on behalf of a struct Date object.
 * Returns the integer value for the supplied date out of 365 or 366 if the date falls within a leap year
 * 
 */
int dayInYear_byDate(struct Date given_date) {
	
	int total_days = dayInYear(given_date.day, given_date.month, given_date.year);
	
	return total_days;
}



/* Returns '1' if the year is a leap year or '0' if not a leap year */
int isLeapYear(int year) {
	
	int is_leap_year; /* value simulate a boolean, 1 if true, 0 if false */
	
	if (year % 4 == 0) {
		
		/* if divisable by 4, the year is a leap year */
		is_leap_year = 1;
		
		/* if divisable by 100 */
		if (year % 100 == 0) {
			/* Year is not a leap year */
			is_leap_year = 0;
		}
		/* if divisible by 400 */
		if (year % 400 == 0) {
			/* LEAP YEAR! */
			is_leap_year = 1;
		}
		
	} else {
		// Year is not a leap year
		is_leap_year = 0;
	}
	
	/* Debugging 
	if (is_leap_year) {
		printf("Year %d is a leap year.\n", year);
	}
	*/
	
	return is_leap_year;
}

/**/
int leap_day_count(struct Date first_date, struct Date second_date) {
	
	// Debugging
	//printf("leap_day_count() called.\n");
	
	// Variable to record the number of leap days between to given dates
	int leap_days = 0;
	
		// Find the Latest and Earliest date
		struct Date *max_date_ptr = max_date(first_date, second_date);
		struct Date *min_date_ptr = min_date(first_date, second_date);
		struct Date max_date = *max_date_ptr;
		struct Date min_date = *min_date_ptr;
		
		
		// DEBUGGING
		// Conditional Variable
		int year_difference = max_date.year - min_date.year;
		// Debugging
		//printf("year_difference: %d\n", year_difference);
		
		// Conditionals
		int min_date_preLeapDay = min_date.month <= 2;
		int max_date_postLeapDay = max_date.month >= 3;
		int max_date_isLeapDay = max_date.month == 2 && max_date.day == 29;
		
		
		/* Debugging Conditionals
		printf("Conditionals (true = 1, false = 0):\n");
		printf("min_date_preLeapDay: %d\n", min_date_preLeapDay);
		printf("max_date_postLeapDay: %d\n", max_date_postLeapDay);
		printf("max_date_isLeapDay: %d\n", max_date_isLeapDay);
		*/
		
		
		if (min_date_preLeapDay && (max_date_postLeapDay || max_date_isLeapDay)) {
			// Debugging
			//printf("leap_days should be incremented by 1.\n");
		}
		
		 
		if (year_difference == 0) {
			
			// If the year difference is zero, is the year a leap year
			if(isLeapYear(min_date.year)) {
				
				// Does 29th of Febuary rest between the dates
				if (min_date_preLeapDay && (max_date_postLeapDay || max_date_isLeapDay)) {
					leap_days = isLeapYear(min_date.year);
				}
				
			}
			
		} else {
		
		// Debugging
		//printf("Seperate Years.\n");
		
			// The earliest date must find the days remaining in its year
			if (isLeapYear(min_date.year)) {
				// Debugging
				//printf("min_date is leap year.\n");
				
				// Check to see if the earliest date exists on or before 29/2
				if(min_date_preLeapDay) {
					// Increment leap_days
					leap_days++;
				}
				
			}
			
					// NOTE: If the years are equal, the for loop will NOT run.
					for(int i = min_date.year + 1; i < max_date.year; i++) {
						
						// Debugging
						//printf("The Current Year is: %d\n", i);
						
						if (i > max_date.year) {
							// Then there is less than a year between the dates
							break;
						}
						
						// Keep track of the leap days
						leap_days += isLeapYear(i);
						
					}
				
				// If max_date is 29/2 or later && the max_date year is a leap year, increment leap_days
				if(max_date_postLeapDay || max_date_isLeapDay) {
					leap_days += isLeapYear(max_date.year);
				}
				
			}
		
	return leap_days;
}


/* Prompts user for user input and stores the result in the provided string.
 *
 * If the user fails to meet formatting or provides an invalid date, then
 * the function maintains a loop of prompting the user.
 *
 * The function requires a pointer to a struct Date so the input may be stored
 * in memory
 */

/* FAILED METHOD ATTEMPTS 
//struct Date * promptUser(char line[]);
//struct Date * promptUser(char line[], struct Date *current_date);
*/

void promptUser(char line[], struct Date *current_date) {
	
	/* Loop until the user provides a valid date */
	while (1) {
			
			/* Local Temporary Vars */
			int date_day;
			int date_month;
			int date_year;
			
			/* Prompt user for first date */
			printf("Enter date (dd/mm/yyyy): ");
			
				/* Read in the line from standard input */
				fgets(line, 100, stdin);
			
				/* Scan the string for integers */
				sscanf(line, "%d/%d/%d", &date_day, &date_month, &date_year);
				
				/* Test to see if the date actually exists */
				if(is_date_valid(date_day, date_month, date_year)) {
					
					/* Debugging printf("Assigning Date to Struct.\n");printf("current_entry pointer: %10p\n", current_date);*/
					
					/* Set the values of struct Date that exists outside this function */
					(*current_date).day = date_day;
					(*current_date).month = date_month;
					(*current_date).year = date_year;

					// If the date has been properly set in the struct then break
					if (is_date_valid((*current_date).day, (*current_date).month, (*current_date).year)) {
						/* Break out of the while loop and continue running the program */
						break;
					} else {
						printf("The struct Date is not actually be created properly.\n");
						continue;
					}
				} else {
					/* the date is invalid, repropt the user for a date */
					printf("The date you have provided is invalid. Check to see if you have formatted the date using dd/mm/yyyy.\n");
					continue;
				}
		}
}

/* Checks to see if the provided date is a real date
 * Returns 1 if the date is valid
 * Returns 0 if the date is invalid
 */
int is_date_valid(int day, int month, int year) {
	
	/* The date is assumed to be true (1)
	 * if it fails the following tests, is_date_real will be set to false (0)
	 */
	int is_date_real = 1; /* is_date_real is true */
	
	if (month < 1 || month > 12) {
		printf("You have entered an invalid month.\n");
		is_date_real = 0;
	} else {
		switch (month) {
					/* Add 31 days for Jan, March, May, July, Aug, Oct and Dec */
							case 1:
							case 3:
							case 5:
							case 7:
							case 8:
							case 10:
							case 12:
								if (day < 1 || day > 31) {
									
									printf("You have entered an invalid day for the given month.\n");
									is_date_real = 0; /* is_date_real is false */
									
								}
								break;
					/* Add 30 days for Apr, June, Sept, and Nov */
							case 4:
							case 6:
							case 9:
							case 11:
								if (day < 1 || day > 30) {
									
									printf("You have entered an invalid day for the given month.\n");
									is_date_real = 0; /* is_date_real is false */
									
								}
								break;
							
					/* Add 28 days for Feb, earlier code handles leap years */
							case 2:
							
								if (isLeapYear(year)) {
									
									if (day < 1 || day > 29) {
										printf("You have entered an invalid day for the given month.\n");
										is_date_real = 0; /* is_date_real is false */
									}
									
								} else if (day < 1 || day > 28) {
									
									printf("You have entered an invalid day for the given month.\n");
									is_date_real = 0; /* is_date_real is false */
									
								}
								break;
								
							default:
							printf("The provided month is not does not exist on the Gregorian Calendar.\n");
							is_date_real = 0; /* is_date_real is false */
								break;
						}
	}
	
	//printf("is_date_real: %d\n", is_date_real);
	
	return is_date_real;
}

/* Format the results to calculate the difference in years and days */
void format_yearDay(int total_days, int leap_days) {
	
	/* Print the difference in years and days */
	int format_years = (total_days - leap_days) / 365;
	int format_days = (total_days - leap_days) % 365;
	printf("The dates are %d years and %d days apart (inlcuding %d leap days).", format_years, format_days, leap_days);
}

/* Format the results to calculate the difference in days */
void format_days(int total_days, int leap_days) {
	printf("\nThe dates are %d days apart (including %d leap days).", total_days, leap_days);
}
