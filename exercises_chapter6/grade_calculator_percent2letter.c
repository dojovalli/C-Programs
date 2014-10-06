/* By: Matthew Valli
 * Purpose: Calculates the hours and minutes from total minutes time
 */

#include <stdio.h>
#include <string.h>

/* Variables */
char line[100]; /* array of characters for input */
float grade; /* given grade in percent */
char letter_grade[2]; /* letter grade (computed) */
int grade_symbol_value; /* math value for symbol calc */
char grade_symbol[2]; /* char symbol for a grade */


int main(int argc, char *argv[]) {
	
	printf("This program calculates the letter grade from percent grade.\n");
	
	/* Ask the user for the width of the rect */
	printf("Enter the grade by percent value: ");
	
	/* Get the users input */
	fgets(line, sizeof(line), stdin);
	
	/* Pull out the float value stored in the string */
	sscanf(line, "%f", &grade);
	
	/* Run the conversion */
	if (grade < 60.0) {
		strcpy(letter_grade,"F");
	}
	if (grade >= 60.0) {
			strcpy(letter_grade,"D");
		}
	if (grade >= 70.0) {
			strcpy(letter_grade,"C");
			}
	if (grade >= 80.0) {
			strcpy(letter_grade,"B");
		}
	if (grade >= 90.0) {
			strcpy(letter_grade,"A");
		}
	
	/* Get the value of the 1's column */
	grade_symbol_value = (int) grade % 10;
	
	/* Only assign a letter symbol if the grade is greater than 60 (an 'F') */
	if (grade >= 60) {
		
		/* Assign a symbol for upper-end letter grades */
		if (grade_symbol_value >= 7 && grade_symbol_value < 10) {
			strcpy(grade_symbol,"+");
		}
		
		/* Assign a symbol for lower-end letter grades */
		if (grade_symbol_value >= 0 && grade_symbol_value < 3) {
			strcpy(grade_symbol,"-");
		}
		
		/* If the grade_symbol_value falls between, no symbol is appended */
	}
	
	
	/* Display the result to the user */
	printf("A %.2f percent grade is an %s%s", grade, letter_grade, grade_symbol);
	
	return(0);
}