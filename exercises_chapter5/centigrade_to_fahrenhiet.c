/* By: Matthew Valli
 * Purpose: Converts degrees Celcius to degrees Fahrenheit
 */

#include <stdio.h>

/* Variables */
char line[100]; /* array of characters for input */
float centigrade; /* degrees of centigrade */
float fahrenheit; /* degrees of fahrenheit (calculated by program) */
const float conversion_constant_C2F = 9.0/5.0; /* Conversion Constant for Cent to Fah */

int main(int argc, char *argv[]) {
	
	printf("This program converts degrees Centigrade to degrees Fahrenheit.\n");
	printf("Enter degrees Centigrade: ");
	
	/* Get the users input */
	fgets(line, sizeof(line), stdin);
	
	/* Pull out the float value stored in the string */
	sscanf(line, "%f", &centigrade);
	
	/* Run the conversion */
	fahrenheit = (conversion_constant_C2F * centigrade) + 32;
	
	/* Display the result to the user */
	printf("%3.2f degrees Celcius is\n%3.2f Fahrenheit", centigrade, fahrenheit);
	
	return(0);
}