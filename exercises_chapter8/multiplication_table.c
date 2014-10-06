#include <stdio.h>

/* Functions */
void multiplication_row(int row_value);
void create_table();
void format_table_position(int current_value);

/* Global Variables */

/* CONSTANTS */
const int TABLE_SIZE = 20;


int main(int argc, char *argv[]) {
	
	// Run the process of creating a table and outputing it to the console
	create_table();
	
}

/* Purpose: Handles the math used to create a single row in the mulitiplication table
 */
void multiplication_row(int row_value) {
	
	// used for storing data during loop iterations
	int current_value;
	
	for (int i = 0; i < TABLE_SIZE; i++) {
		
		// Multiply the row value to find each columns value
		current_value = row_value * (i + 1);
		
		// Format the output based how many digits the current_value has
		format_table_position(current_value);
		
	}
	
}

/* Purpose: Handles printing of individual rows of the table
 * 			incrementing the row's factor
 * 			and placing it on a new line
 */
void create_table() {
	
	// Print out each row individually, incrementing the current row's value
	for (int i = 0; i < TABLE_SIZE; i++) {
		
		multiplication_row(i + 1);
		printf("\n");
		
	}
	
}


/* Purpose: Handles logic for spacing the output for readability
 */
void format_table_position(int current_value) {
	
	// Add space between columns
	printf(" ");
	
	// If the number has at least two digits
	if (current_value / 10) {
		
			// If the current value has at least three digits
			if (current_value / 100) {
				// Print the value
				printf("%d", current_value);
			} else {
				printf(" %d", current_value);
			}
			
		} else {
			printf("  %d", current_value);
		}
	
}


