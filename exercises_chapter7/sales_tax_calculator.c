#include <stdio.h>

/* Variables */
char line[100]; /* string for user input */
float input_subtotal; /* used to convert float input to int */
int subtotal; /* used as the subtotal for calculations */
float sales_tax = 0.08; /* Sales tax in percent, not decimal */
float tax_total; /* Cost of tax (computed) */
float total_price; /* Value of final sale, inclusive of tax */


int main(int argc, char *argv[]) {
	
	/* Prompt the user with the purpose of the program */
	printf("This program calculates the sales tax of a purchase, based on a supplied subtotal.\n");
	
	/* Prompt the user for input */
	printf("Enter the Subtotal: $");
	
	/* Gather input from the user */
	fgets(line, sizeof(line), stdin);
	
	/* Scan the string for a float value */
	sscanf(line, "%f", &input_subtotal);
	
	
	/* Convert from float to integer (Penny Value) */
	subtotal = (int) (input_subtotal * 100);
	
	/* Run Calculation */
	tax_total = subtotal * sales_tax;
	total_price = (subtotal / 100) + (tax_total / 100);
	
	
	/* Display output to user */
	printf("\n");
	printf("Subtotal: $%.2f\n", input_subtotal);
	printf("Tax: $%.2f\n", (tax_total / 100));
	printf("Total: $%.2f\n", total_price);
	

}