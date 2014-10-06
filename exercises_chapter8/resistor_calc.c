#include <stdio.h>

/* Functions */
void program_purpose();
void prompt_user();
void run_program();
void combine_resistor_factor(int numerator, int denominator);
int refactor_adjustment(int denominator);
void modify_fraction(int denominator);


/* Global Variables */
char line[100];
int common_denominator = 1;
int common_numerator = 0;
int current_denominator;
int current_numerator;



int main(int argc, char *argv[]) {
	
	program_purpose();
	
	run_program();
	
	printf("End of Program.");
	
}


void program_purpose() {
	
	printf("The program calculates the total resistance provided by the combination of resistor factors.\n");
	printf("\n");
	
}


void prompt_user() {
	
	// Prompt User for input
	printf("Input resistor fraction: ");
	
	// Retrieve User Input
	fgets(line, sizeof(line), stdin);
	
	// Break data apart for storage
	sscanf(line, "%d/%d", &current_numerator, &current_denominator);
	
}

void run_program() {
	
	// Used for logging the pass of each loop
	int i = 0;
	
	while(1) {
	
	// Prompt User for resistor factor
	prompt_user();
	
	// Break on sentinal
	if(current_denominator == 0 || current_numerator == 0) {
		printf("Breaking Run Program Loop\n");
		printf("current_denominator: %d\n", current_denominator);
		printf("current_numerator: %d\n", current_numerator);
		
		break;
	}
	
	// Calculate resistor_denominator
	combine_resistor_factor(current_numerator, current_denominator);
	
	// Increment Loop Counter
	i++;
	
	// Testing
	printf("\n");
	printf("Input Pass %d\n", i);
	printf("common_n: %d\n", common_numerator);
	printf("common_d: %d\n", common_denominator);
	printf("current_denominator: %d\n", current_denominator);
	printf("current_numerator: %d\n", current_numerator);
	printf("\n");
	
	}
	
}

void combine_resistor_factor(int numerator, int denominator) {
	
	// log
	printf("crf_numerator: %d\n", numerator);
	/**/
	// If the numerator hasn't been set, set its value (must be first pass of loop)
	if (common_numerator == 0) {
		common_numerator = numerator;
	}
	
	// If the denominator isn't the same as the common_denominator
	if (denominator != common_denominator) {
		
		// Log
		printf("The current denominator should be the new common_denominator.\n");
		
		// Adjust the values of program totals
		int multiplier = refactor_adjustment(denominator);
		
		
			if (denominator < common_denominator) {
				// Add the current numerator to the adjusted common_numerator
				common_numerator += numerator * multiplier;
			}
			
			if (denominator > common_denominator) {
				
				// Add the current_numerator, the common_fraction has already been adjusted
				common_numerator += numerator;
			}
		
		
		
	} else if (denominator == common_denominator) {
		
		// Add the current numerator to the common_numerator
		common_numerator += numerator;
		
	}
	
}

int refactor_adjustment(int denominator) {
	
	// Adjustment_factor defaults to 1
	int adjustment_factor = 1;
	
	// No adjustment needed if the factors are the same
	if (denominator == common_denominator) {
		return adjustment_factor;
	}
	
	if (denominator > common_denominator) {
		
		// If the common_d is evenly divisible by the denominator, the calculated value is the adj_factor
		if (denominator % common_denominator  == 0) {
			
			
			if (common_denominator != 1) {
			
				// Expand the common_fraction (common_numerator / common_denominator)
				adjustment_factor = denominator / common_denominator;
				printf("adj_factor: %d\n", adjustment_factor);
				
				// Adjust the numerator value accordingly to the adjustment_factor
				common_numerator = common_numerator * adjustment_factor;
				
				// Log
				printf("Refactored common_n: %d\n", common_numerator);
			}
			
			// Set the common_denominator to the current_denominator
			common_denominator = denominator;
			printf("Refactored common_d: %d\n", common_denominator);
			
		} else {
			printf("Modifying Fraction.\n");
			modify_fraction(denominator);
		}
		
		
		
	} else {
		
		
		
		printf("Need code to handle a smaller denominator.\n");
		
	}
	
	return adjustment_factor;
}

void modify_fraction(int denominator) {
	
	// Local Vars
	int new_denominator;
	int new_numerator;
	int new_current_numerator;
	
	// Calculate new_denominator by multiplying the current_den. and common_den.
	new_denominator = common_denominator * denominator;
	new_numerator = common_numerator * denominator;
	new_current_numerator = current_numerator * common_denominator;
	
	// Reset the values for the program
	common_denominator = new_denominator;
	common_numerator = new_numerator;
	current_numerator = new_current_numerator;
	
}