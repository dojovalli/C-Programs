/* By: Matthew Valli
 * Purpose: Calculates the value of a sphere based on user input of the radius
 */

#include <stdio.h>
#include <math.h>

/* Variables */
char line[100]; /* array of characters for input */
char line2[100]; /* array of characters for input */
float height; /* height of rect */
float width; /* width of rect */
float perimeter; /* perimeter of rect (computed) */


int main(int argc, char *argv[]) {
	
	printf("This program calculates the perimeter of a rectangle.\n");
	
	/* Ask the user for the height of the rect */
	printf("Enter the height of the rectangle: ");
	
	/* Get the users input */
	fgets(line, sizeof(line), stdin);
	
	/* Pull out the float value stored in the string */
	sscanf(line, "%f", &height);
	
	/* Ask the user for the width of the rect */
	printf("Enter the width of the rectangle: ");
		
		/* Get the users input */
		fgets(line2, sizeof(line2), stdin);
		
		/* Pull out the float value stored in the string */
		sscanf(line2, "%f", &width);
	
	/* Run the conversion */
	perimeter = 2 * (height + width);
	
	/* Display the result to the user */
	printf("The perimeter of a rectangle is: %.2f units", perimeter);
	
	return(0);
}