/* By: Matthew Valli
 * Purpose: Converts kilometers to miles
 */

#include <stdio.h>
#include <math.h>

/* Variables */
char line[100]; /* array of characters for input */
float kilometers; /* height of rect */
float miles; /* perimeter of rect (computed) */
const float conversion_constant_km2mi = 0.6213712;


int main(int argc, char *argv[]) {
	
	printf("This program calculates the miles from kilometers.\n");
	
	/* Ask the user for the height of the rect */
	printf("Enter the value in kilometers: ");
	
	/* Get the users input */
	fgets(line, sizeof(line), stdin);
	
	/* Pull out the float value stored in the string */
	sscanf(line, "%f", &kilometers);
	
	
	/* Run the conversion */
	miles = kilometers * conversion_constant_km2mi;
	
	/* Display the result to the user */
	printf("%.2f kilometers = %.2f miles", kilometers, miles);
	
	return(0);
}