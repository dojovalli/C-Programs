#include <stdio.h>
#include <string.h>

/* Functions */
void program_purpose();
void run_program();
int prompt_user();
void value_to_word(int input);



/* Global Variables */
char line[100];
char output[1000];


int main(int argc, char *argv[]) {

	// Variable for user input
	int input;
	
	// State the purpose of the program
	program_purpose();
	
	// Run the program
	run_program();
	
}


void program_purpose() {
	
	printf("This program returns the verbalization of the inputed integer.\n");
	
}



int prompt_user() {
	
	// Temporary Variables
	int user_input;

	// Prompt User for input
	printf("Enter number: ");
	
	// Get the user input
	fgets(line, sizeof(line), stdin);
	
	// Parse the line for a float number
	sscanf(line, "%d", &user_input);

	return user_input;	
}


void run_program() {
	
	// Prompt the user for input and store the value
	int user_input = prompt_user();
	
	// Convert the value to words
	value_to_word(user_input);
	
	// Print the output to the console
	printf("Verbal: %s", output);
	
}

void value_to_word(int input) {
	
	switch (input) {
		case 0:
			strcat(output, "zero");
			break;
		case 1:
			strcat(output, "one");
			break;
		case 2:
			strcat(output, "two");
			break;
		case 3:
			strcat(output, "three");
			break;
		case 4:
			strcat(output, "four");
			break;
		case 5:
			strcat(output, "five");
			break;
		case 6:
			strcat(output, "six");
			break;
		case 7:
			strcat(output, "seven");
			break;
		case 8:
			strcat(output, "eight");
			break;
		case 9:
			strcat(output, "nine");
			break;
	}
	
}


