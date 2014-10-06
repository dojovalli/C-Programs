#include <stdio.h>

/* Functions */
void program_purpose();
int prompt_user();
void increment_count(int user_input);
void format_results();
void run_count();


/* Global Variables */
const int SENTINAL = 0;
int total_count = 0;
int neg_count = 0;
int pos_count = 0;
char input[30];


int main(int argc, char *argv[]) {
	program_purpose();
	run_count();
	format_results();
}


void program_purpose() {
	printf("This program prompts the user for numbers until they enter a sentinal (0).\nThe program then displays the count of both positive and negative numbers.\n\n");
}


int prompt_user() {
	
	int input_value;
	
	// Prompt the user for new number
	printf("Enter the %d number: ", (total_count + 1));
			
	// Get the input from the user
	fgets(input, sizeof(input), stdin);
			
	// Extract the data from the string
	scanf("%d", &input_value);
	
	return input_value;
}


void increment_count(int user_input) {
	
	//printf("user_input (inside increment_count): %d\n", user_input);

		if(user_input > 0) {
			// Increment the positive number count
			pos_count++;
		}
		
		if(user_input < 0) {
			// Increment the negative number count
			neg_count++;
		}
		
		// Increment the total_count
		total_count++;
	
	return;
}

void format_results() {
	printf("You entered %d numbers.\n", total_count);
	printf("There were %d negative numbers.\n", neg_count);
	printf("There were %d positive numbers.\n", pos_count);
	
}

void run_count() {
	
	// Loop until user enters SENTINAL (0)
	while (1) {
		
		// Prompt User for input, store input in temp 'user_input' var
		int user_input = prompt_user();
		
		// Debugging
		printf("user_input: %d\n", user_input);
		
		if (user_input == SENTINAL) {
			break;
		}
		
		// Increment the count of the appropriate variables
		increment_count(user_input);
		
	}
	
}
