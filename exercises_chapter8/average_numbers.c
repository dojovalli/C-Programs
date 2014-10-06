#include <stdio.h>

/* Functions */
void run_program();
void program_purpose();
float prompt_user();
float average_numbers (float total, int count);


/* CONSTANTS */
const int SENTINAL = 0;


/* Global Variables */
float total = 0;
int count = 0;
char line[100];


int main(int argc, char *argv[]) {
	
	// Prompt the user with the purpose of the program
	program_purpose();
	
	// Repetitively prompt the user for input until the SENTINAL is reached
	run_program();
	
	// DEBUGGING
	//printf("main total: %f\n", total);
	
	// Average the numbers
	float average = average_numbers(total,count);
	
	// Format the average for output to the user
	printf("The average of the %d provided numbers is: %.2f", count, average);
}

void program_purpose() {
	
	printf("This program returns the average of numbers input by the user after the setinal (0) is returned.\n");
	
}

void run_program() {
	
	float user_input;
	
	// Loop using Loop & a Half Technique
	while(1) {
		
		// Prompt the user for input
		user_input = prompt_user();
		
		// Exit the loop if the SENTINAL is reached, cast the user_input to an integer
		if (((int) user_input) == SENTINAL) {
			break;
		}
		
		// Add the user_input to the total
		total += user_input;
		
		// DEBUGGING
		//printf("total: %f\n", total);
		
		// Increment the count of inputs taken
		count++;
		
	}
	
}


float prompt_user() {
	
	// Temporary Variables
	float user_input;

	// Prompt User for input
	printf("Enter number: ");
	
	// Get the user input
	fgets(line, sizeof(line), stdin);
	
	// Parse the line for a float number
	sscanf(line, "%f", &user_input);

	return user_input;	
}

float average_numbers (float total, int count) {
	
	// Temporary Variables
	float average;
	
	// Average the numbers
	average = total / (float) count;
	
	return average;
}

