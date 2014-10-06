/* date_interval.c
 * By: Matthew Valli
 * 
 * Purpose: To calculate the interval between to provided dates
 */

#include <stdio.h>
#include <math.h>

/* Function Names */
// Struct Functions
//void date_description(struct Date *given_date);
int date_difference(struct Date first_date, struct Date second_date);
struct Date * max_date(struct Date first_date, struct Date second_date);

// Date Calculation Methods
int dayInYear (int day, int month, int year);
int is_date_valid(int day, int month, int year);
int isLeapYear(int year);

// Simple Convienence Methods
int max(int first, int second);
int min(int first, int second);


/* Date Structure Type Definition */
struct Date {
	int day;
	int month;
	int year;
};


/* Variables - user input */
char line_1[11]; /* user input format: dd/mm/yyyy (10 char) + EOL char (11 char total) */
char line_2[11]; /* user input format: dd/mm/yyyy (10 char) + EOL char (11 char total) */

struct Date date_1;
struct Date date_2;
struct Date date_max;
struct Date *date_max_ptr;
struct Date date_min;
//struct date *date_min;

/* Temp Global Vars */
int date_1_day;
int date_1_month;
int date_1_year;
int date_2_day;
int date_2_month;
int date_2_year;

/* Variables - determining interval */


int days; /* number of days left in the week */
int weeks; /* number of weeks left in the month */
int months; /* number of months left in the year */
int years; /* number of years left in the month */

int total_days; /* total number of days between the two dates provided (computed) */


/* Functions using Structs as arguments - MUST PROCEED MAIN FUNCTION */
/* Prints a description of the date struct */
void date_description(struct Date * given_date) {
	
	printf("Printing date struct: %d/%d/%d\n", given_date->day, given_date->month, given_date->year);
	
}

int main(int argc, char *argv[]) {
	
	printf("This program calculates the interval between to provided dates (dd/mm/yyyy).\n");
	
	/* Program Vars */
	struct Date date_1;
	struct Date date_2;
	
	while (1) {
		
		/* Prompt user for first date */
		printf("Enter the first date (dd/mm/yyyy): ");
		
			/* Read in the line from standard input */
			fgets(line_1, sizeof(line_1), stdin);
		
			/* Scan the string for integers */
			sscanf(line_1, "%d/%d/%d", &date_1_day, &date_1_month, &date_1_year);
			
			/* Test to see if the date actually exists */
			if(is_date_valid(date_1_day, date_1_month, date_1_year)) {
				
				/* The date is valid, create the Date struct */
				struct Date date_1 = {date_1_day, date_1_month, date_1_year};
				
				date_description(&date_1);
				
				/* Break out of the while loop and continue running the program */
				break;
			} else {
				/* the date is invalid, repropt the user for a date */
				printf("The date you have provided is invalid. Check to see if you have formatted the date using dd/mm/yyyy.\n");
				continue;
			}
		
	}
	
	/* Prompt the user for the second date */
	while (1) {
			
			/* Prompt user for first date */
			printf("Enter the second date (dd/mm/yyyy): ");
			
				/* Read in the line from standard input */
				fgets(line_2, sizeof(line_2), stdin);
			
				/* Scan the string for integers */
				sscanf(line_2, "%d/%d/%d", &date_2_day, &date_2_month, &date_2_year);
				
				/* Test to see if the date actually exists */
				if(is_date_valid(date_2_day, date_2_month, date_2_year)) {
					
					/* The date is valid, create the Date struct */
					struct Date date_2 = {date_2_day, date_2_month, date_2_year};
					
					/* Break out of the while loop and continue running the program */
					break;
				} else {
					/* The date is invalid, repropt the user for a date */
					printf("The date you have provided is invalid. Check to see if you have formatted the date using dd/mm/yyyy.\n");
					continue;
				}
			
		}
		
	/* Sort the Dates by Min (Earliest) and Max (Latest) */
	// Store the result of max_date() - a pointer to the latest date - in a pointer of struct Date
	 struct Date *max_date_ptr = max_date(date_1, date_2);
	 
	 // Use the pointer of struct Date to initialize the struct Date max_date to the returned by the max_date() function
	 struct Date date_max = *max_date_ptr;
	printf("date_max = ");
	date_description(&date_max);
		
	
	/* Run Calculation */
	/* Calculation Variables */
	int total_days_date_min;
	int total_days_date_max;
	int year_difference;
	
	
	/* Find the difference between the years */
	int year_max = max(date_1_year, date_2_year);
	int year_min = min(date_1_year, date_2_year);
	
	
	
	year_difference = year_max - year_min;
	printf("year_difference = %d\n", year_difference);
	total_days = 365 * (year_difference - 1);
	
	/* Find remaining days in each year */
	total_days_date_min = dayInYear(date_1_day,date_1_month,date_1_year);
	total_days_date_max = dayInYear(date_2_day,date_2_month,date_2_year);
	
	printf("total_days_date_min = %d\n", total_days_date_min);
	printf("total_days_date_max = %d\n", total_days_date_max);
	
	if (date_1_year == date_2_year) {
		
		total_days = total_days_date_max - total_days_date_min;
		
	} else {
		
		total_days += total_days_date_max + (365 - total_days_date_min);
		
	}
	
	printf("Total Days: %d\n", total_days);
	
	
	/* Print the difference in years and days */
	int format_years = total_days / 365;
	int format_days = total_days % 365;
	printf("A difference of %d years and %d days.", format_years, format_days);
	
	
	
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
		
		printf("The years are equal, testing month.\n");
		
		/* The dates are from the same year, check the months */
		if (first_date.month > second_date.month) {
				max_ptr = &first_date;
			} else if (first_date.month < second_date.month) {
				max_ptr = &second_date;
			} else {
				
				printf("The years and months are equal, testing day.\n");
				
				/* The dates are from the same month and year, we must check the difference in days */
				if (first_date.day > second_date.day) {
						max_ptr = &first_date;
					} else if (first_date.day < second_date.day) {
						max_ptr = &second_date;
					} else {
						printf("The dates are the same, returning the first date argument.\n");
						max_ptr = &first_date;
					}
			}
	}
	
	return max_ptr;
}

/* Returns the earliest of two dates */
/*
int date_difference(struct Date first_date, struct Date second_date) {
	
	int difference_in_days = 0;
	
	// If the year is a leap year
		if (isLeapYear(year)) {
			
			// Add a day if the date is past Feb 28
			if (month >= 2) {
				
				if (month >= 3 || (month == 2 && day == 29)) {
					// Add a day to the dayInYear count
					dayInYear +=1;
					
					// Debugging
					printf("Added day for leap year.\n");
				}
			}
		}

	return difference_in_days;
}
*/
int date_difference (struct Date first_date, struct Date second_date) {
	/* Calculation Variables */
		int total_days_date_min;
		int total_days_date_max;
		int year_difference;
		
		
		/* Find the difference between the years */
		int year_max = max(first_date.year, second_date.year);
		int year_min = min(first_date.year, second_date.year);
		
		
		
		year_difference = year_max - year_min;
		printf("year_difference = %d\n", year_difference);
		total_days = 365 * (year_difference - 1);
		
		/* Find remaining days in each year */
		total_days_date_min = dayInYear(first_date.day,first_date.month,first_date.year);
		total_days_date_max = dayInYear(second_date.day,second_date.month,second_date.year);
		
		printf("total_days_date_min = %d\n", total_days_date_min);
		printf("total_days_date_max = %d\n", total_days_date_max);
		
		if (first_date.year == second_date.year) {
			
			total_days = total_days_date_max - total_days_date_min;
			
		} else {
			
			total_days += total_days_date_max + (365 - total_days_date_min);
			
		}

	return total_days;
}

int date_difference (struct Date first_date, struct Date second_date) {
	
	// Variable to store the total days between the dates
	int total_days = 0;
	
	// Find the Latest and Earliest date
	struct Date *max_date_ptr = max_date(first_date, second_date);
	struct Date *min_date_ptr = min_date(first_date, second_date);
	struct Date max_date = *max_date_ptr;
	struct Date min_date = *min_date_ptr;
	
	// Conditional Variable
	int year_difference = max_date.year - min_date.year;
	
	
	if (year_difference == 0) {
		
		/* Subtract the dayInYear Value of min_date from max_date */
		total_days = dayInYear(max_date) - dayInYear(min_date);
		
	} else {
	
		/* NOTE: If the years are equal, the for loop will NOT run. */
		for(int i = min_date.year + 1; i < max_date.year; i++) {
			
			if (i > max_date.year) {
				// Then there is less than a year between the dates
				break;
			}
			
			// Add 365 for a full year
			total_days += 365;
			
			// if the year is a leap year, add an extra day. isLeapYear() returns 1 if true, else 0
			total_days += isLeapYear(i);
			
		}
		
		// Add the dayInYear value for the max_date
		total_days += dayInYear(max_date);
		
		// Subtract the dayInYear value from the 365 (and a potentional leap day)
		total_days += dayInYear(min_date)
	
	}
	
	return total_days;
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
int dayInYear(struct Date given_date) {
	
	int total_days = dayInYear(given_date.day, given_date.month, given_day.year);
	
	return total_days;
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
	
	return is_date_real;
}
	
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
	
	return is_leap_year;
}

/* returns the highest value, if the values are the same the first value is returned */
int max(int first, int second) {
	
	int max;
	
	if (first >= second) {
		max = first;
	} else {
		max = second;
	}
	
	return max;
}

/* returns the lowest value, if the values are the same the first value is returned */
int min(int first, int second) {
	
	int min;
	
	if (first <= second) {
		min = first;
	} else {
		min = second;
	}
	
	return min;
}





