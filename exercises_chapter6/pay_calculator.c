/* By: Matthew Valli
 * Purpose: Calculates the wages of an employee by hour over the period of a week
 *
 * Note: Any hour over the overtime_period (currently 40 hours) is calculated at time and a half
 */

#include <stdio.h>
#include <math.h>

/* Variables */
char line[100]; /* array of characters for input */
char line2[100]; /* array of characters for input */
float hours; /* hours worked in a week */
float wage; /* wage per hour */
float pay; /* pay due for employee (computed) */
float overtime; /* overtime hours (computed) */
float time_and_half; /* time & half (computed) */
const float overtime_period = 40.0; /* Overtime Period Constant */



int main(int argc, char *argv[]) {
	
	printf("This program calculates the wages of an employee by hour over the period of a week.\n");
	
	/* Ask the user for the height of the rect */
	printf("Enter the hours worked this week: ");
	
		/* Get the users input */
		fgets(line, sizeof(line), stdin);
	
		/* Pull out the float value stored in the string */
		sscanf(line, "%f", &hours);
	
	/* Ask the user for the width of the rect */
	printf("Enter the wage per hour of the employee: $");
		
		/* Get the users input */
		fgets(line2, sizeof(line2), stdin);
		
		/* Pull out the float value stored in the string */
		sscanf(line2, "%f", &wage);
	
	/* Run the conversion */
	/* if the employee worked less than 40 hours this week */
	if (hours > overtime_period) {
		
		// Calculate overtime hours
		overtime = hours - overtime_period;
		
		// Calculate time and half
		time_and_half = overtime * 1.5;
	}
	
	// Calculate pay
	pay = ((hours - overtime) + time_and_half) * wage;
	
	/* Display the result to the user */
	printf("\n");
	printf("Pay Details\n");
	printf("Payrate: $%.2f/hour\n", wage);
	printf("Hours: %.2f\n", hours);
	printf("Overtime: %.2f\n", overtime);
	printf("\n");
	printf("Pay: $%.2f", pay);
	
	
	return(0);
}