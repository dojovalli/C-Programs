/* By: Matthew Valli
 * Purpose: Calculates the value of a sphere based on user input of the radius
 */

#include <stdio.h>
#include <math.h>

/* Variables */
char line[100]; /* array of characters for input */
float radius; /* radius of sphere */
float volume; /* volume of sphere (computed) */
const float volume_const_sphere = 4.0/3.0; /* constant for spherical calculations */
/* Pi is a language-defined constant M_PI */

int main(int argc, char *argv[]) {
	
	printf("This program calculates the volume of a sphere.\n");
	printf("Enter the value of the radius: ");
	
	/* Get the users input */
	fgets(line, sizeof(line), stdin);
	
	/* Pull out the float value stored in the string */
	sscanf(line, "%f", &radius);
	
	/* Run the conversion */
	volume = volume_const_sphere * M_PI * radius * radius * radius;
	
	/* Display the result to the user */
	printf("A sphere with the radius %.2f units has a volume of: %.2f units-cubed", radius, volume);
	
	return(0);
}