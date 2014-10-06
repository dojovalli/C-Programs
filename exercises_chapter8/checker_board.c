#include <stdio.h>

/* Functions */
void pattern_top(int number_of_columns);
void pattern_middle(int number_of_columns);
void add_row(int number_of_columns);

/* CONSTANTS */
const int BOARD_WIDTH = 8;  /* Number of Columns */
const int BOARD_HEIGHT = 8; /* Number of Rows */
const int SEGMENT_HEIGHT = 3; /* Number of lines determining individual cell height */
const int SEGMENT_WIDTH = 5; /* Number of characters determining individual cell width */

/* Equal Spacing Settings:
	BOARD_WIDTH = 8;
	BOARD_HEIGHT = 8;
	SEGMENT_HEIGHT = 1;
	SEGMENT_WIDTH = 4;
*/




int main(int argc, char *argv[]) {
	
	// Build top of BOARD using pattern_top()
	pattern_top(BOARD_WIDTH);
	
	// Add the add number of rows
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		
		// Add each row individual during each pass of the loop
		add_row(BOARD_WIDTH);
		
	}
}

/* Purpose: To create a single line representing the division between rows
 */
void pattern_top(int number_of_columns) {
	
	// Start with the initial char '+' for the origin of the pattern
	printf("+");
	
	for (int i = 0; i < number_of_columns; i++) {
		
		
		
		// Adds an individual segement of the row that represents a column
		// Customize the segement size using COLUMN_WIDTH
		for(int i = 0; i < SEGMENT_WIDTH; i++) {
			printf("-");
		}
		
		// Close the corner of the segment
		printf("+");
		
	}
	
	// Move down to the next line
	printf("\n");
	
}

/* Purpose: To create a single line representing the division between columns
 */
void pattern_middle(int number_of_columns) {
	
	// Start with the intial character for the column wall
	printf("|");
			
	for (int i = 0; i < number_of_columns; i++) {
		
		for(int i = 0; i < SEGMENT_WIDTH; i++) {
			printf(" ");
		}
				
		// Close off the column
		printf("|");
				
	}
			
	// Move down to the next line
	printf("\n");
	
}

/* Purpose: Combines the logic to build a complete row under the a pre-condition.
 * 
 * Pre-Condition: a row or pattern_top is present above new row.
 * 
 * Argument: (int row width) takes input for the number of columns in the given row
 */
void add_row(int number_of_columns) {
	
	// Each Row has a 3 line height
	for(int i = 0; i < SEGMENT_HEIGHT; i++) {
		
		pattern_middle(number_of_columns);
	
	}
	
	// Close the bottom of the row
	pattern_top(number_of_columns);
	
}