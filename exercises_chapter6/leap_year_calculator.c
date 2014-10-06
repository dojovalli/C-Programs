/* By: Matthew Valli
 * Purpose: Calculates whether the given year is a leap year
 */

#include <stdio.h>
#include <string.h>

/* Variables */
char line[100]; /* array of characters for input */
int given_year; /* given year */
int is_leap_year; /* false == 0, true == 1 */



int main(int argc, char *argv[]) {
	
	printf("This program calculates whether the given year is a leap year.\n");
	
	/* Ask the user for the value of change to return */
	printf("Enter the year you would like to test: ");
	
	/* Get the users input */
	fgets(line, sizeof(line), stdin);
	
	/* Pull out the float value stored in the string */
	sscanf(line, "%d", &given_year);
	
	
	/* Run the conversion */
	if (given_year % 4 == 0) {
		
		/* if divisable by 4, the year is a leap year */
		is_leap_year = 1;
		
		/* if divisable by 100 */
		if (given_year % 100 == 0) {
			/* Year is not a leap year */
			is_leap_year = 0;
		}
		/* if divisible by 400 */
		if (given_year % 400 == 0) {
			/* LEAP YEAR! */
			is_leap_year = 1;
		}
		
	} else {
		// Year is not a leap year
		is_leap_year = 0;
	}
	
	/* Display the result to the user */
	if (is_leap_year) {
		printf("%d is a leap year!", given_year);
	} else {
		printf("%d is not a leap year.", given_year);
	}
	
	return(0);
}