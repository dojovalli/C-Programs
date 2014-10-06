/* By: Matthew Valli
 * Purpose: Calculates the total minutes from hours and minutes time 
 */

#include <stdio.h>
#include <math.h>

/* Variables */
char line[100]; /* array of characters for input */
char line2[100]; /* array of characters for input */
int hours; /* given hours */
int minutes; /* given minutes */
int total_minutes; /* minutes (computed) */


int main(int argc, char *argv[]) {
	
	printf("This program calculates the minutes based on hours and minutes.\n");
	
	/* Ask the user for the height of the rect */
	printf("Enter hours: ");
	
	/* Get the users input */
	fgets(line, sizeof(line), stdin);
	
	/* Pull out the float value stored in the string */
	sscanf(line, "%d", &hours);
	
	/* Ask the user for the width of the rect */
	printf("Enter minutes: ");
		
		/* Get the users input */
		fgets(line2, sizeof(line2), stdin);
		
		/* Pull out the float value stored in the string */
		sscanf(line2, "%d", &minutes);
	
	/* Run the conversion */
	total_minutes = (hours * 60) + minutes;
	
	/* Display the result to the user */
	printf("%d hours and %d minutes = %d minutes", hours, minutes, total_minutes);
	
	return(0);
}