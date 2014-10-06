/* By: Matthew Valli
 * Purpose: Calculates the hours and minutes from total minutes time
 */

#include <stdio.h>
#include <math.h>

/* Variables */
char line[100]; /* array of characters for input */
int hours; /* given hours */
int minutes; /* given minutes */
int total_minutes; /* minutes (computed) */


int main(int argc, char *argv[]) {
	
	printf("This program calculates the hours and minutes based on total minutes .\n");
	
	/* Ask the user for the width of the rect */
	printf("Enter minutes: ");
	
	/* Get the users input */
	fgets(line, sizeof(line), stdin);
	
	/* Pull out the float value stored in the string */
	sscanf(line, "%d", &total_minutes);
	
	
	/* Run the conversion */
	hours = total_minutes / 60;
	minutes = total_minutes % 60;
	
	/* Display the result to the user */
	printf("%d minutes = %d hours and %d minutes", total_minutes, hours, minutes);
	
	return(0);
}