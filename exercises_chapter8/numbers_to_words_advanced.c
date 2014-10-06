#include <stdio.h>


/* Functions */
void program_purpose();
void run_program();
long prompt_user();
void handle_long_numbers();
void handle_hundreds(int number);
void handle_number(int number);
void handle_teens(int teen);
void handle_tens(int tens);
int count_digits(char string[]);


/* Global Variables */
char line[100];


int main(int argc, char *argv[]) {

	program_purpose();
	
	while (1) {
		// Prompt the user for input and store the value
		long user_input = prompt_user();
		
		// Exit loop if user enters zero
		if (user_input == 0) {
			printf("\n");
			printf("The number is Zero.\nProgram Exited.");
			break;
		}

		// Compute Written English for the user_input
		handle_long_numbers(user_input);
		
		// Return to next line for next series in loop
		printf("\n\n");
	}
	
}


void program_purpose() {
	
	printf("This program returns the written English of the inputted integer (up to 2^30).\n");
	
}

/* Used to run program outside of loop */
void run_program() {
	
	// Prompt the user for input and store the value
	long user_input = prompt_user();

	// Compute Written English for the user_input
	handle_long_numbers(user_input);
}


long prompt_user() {
	
	// Temporary Variables
	long user_input;

	// Prompt User for input
	printf("Enter number: ");
	
	// Get the user input
	fgets(line, sizeof(line), stdin);
	
	// Parse the line for a float number
	sscanf(line, "%ld", &user_input);

	return user_input;	
}



/* Handle 'long' numbers since they have a greater range than 'int'
 * Reason: This extends the range of computation capable for the program to 2^30 */
void handle_long_numbers(long number) {
	
	// Break down numbers into hundreds of XXX digits
	int trillions = number / 1000000000000;
	int billions = (number - (trillions * 1000000000000)) / 1000000000;
	int millions = (number - (trillions * 1000000000000) - (billions * 1000000000)) / 1000000;
	int thousands = (number - (trillions * 1000000000000) - (billions * 1000000000) - (millions * 1000000)) / 1000;
	int remainder = number % 1000;
	
	/* Debugging
	printf("trillions: %d", trillions);
	printf("billions: %d", billions);
	printf("millions: %d", millions);
	printf("thousands: %d", thousands);
	printf("remaining: %d\n", remainder);
	*/
	
	
	// Count the number of digits from the string for switching
	int digits = count_digits(line);
	
	// Use the number of digits to determine whether the number is in thousands, millions, billions, etc.
	switch (digits) {
		case 13:
		case 14:
		case 15:
			handle_hundreds(trillions);
			printf(" Trillion\n");
		
		case 10:
		case 11:
		case 12:
			handle_hundreds(billions);
			printf(" Billion\n");
		
		case 7:
		case 8:
		case 9:
			handle_hundreds(millions);
			printf(" Million\n");
		
		case 4:
		case 5:
		case 6:
			handle_hundreds(thousands);
			printf(" Thousand\n");
		case 1:
		case 2:
		case 3:
			handle_hundreds(remainder);
			break;
	}
	
}


void handle_hundreds(int number) {

	// Number breakdown
	// Pull out the digits individually
	int hundreds = number / 100;
	int tens = (number - (hundreds * 100)) / 10;
	int ones = number - (hundreds * 100) - (tens * 10);
	
	/* Debugging
	printf("Hundreds: %d\n", hundreds);
	printf("Tens: %d\n", tens);
	printf("Ones: %d\n\n", ones);
	*/
	
	// Vocabulary is determined by Hundreds, Tens, and Ones
	// If hundreds is more than 0 and less than 10, we print, else the digit is handled else where
	if (hundreds != 0 && hundreds < 10) {
		handle_number(hundreds);
		printf(" Hundred");
	}
	
	// If there is a value other than zero, we must print out the written tens value
	if (tens > 0) {
		
		if (hundreds > 0) {
			// A space is needed to seperate tens from the hundreds, only if hundreds exists
			printf(" ");
		}
		
		switch (tens) {
			case 1:
				// Handles exceptions between 10 and 20
				handle_teens(ones);
				break;
			default:
				// Handles regular numbering patterns
				handle_tens(tens);
				break;
		}
	}
	
	if (ones != 0) {
		
		if (tens > 1) {
			// Hyphens are use to seperate tens and ones places
			printf("-");
			handle_number(ones);
		} else if (tens == 0 && hundreds > 0) {
			// Spaces are used between hundres and ones if tens are absent in written English
			printf(" ");
			handle_number(ones);
		} else if (tens == 0 && hundreds == 00) {
			// Else there is only a single digit number
			handle_number(ones);
		}
		
	}
			
}

/* Handles printing any single digits verbal value to the console */
void handle_number(int number) {
	
	switch (number) {
			case 0:
				break;
			case 1:
				printf("One");
				break;
			case 2:
				printf("Two");
				break;
			case 3:
				printf("Three");
				break;
			case 4:
				printf("Four");
				break;
			case 5:
				printf("Five");
				break;
			case 6:
				printf("Six");
				break;
			case 7:
				printf("Seven");
				break;
			case 8:
				printf("Eight");
				break;
			case 9:
				printf("Nine");
				break;
		}
}

/* Handles printing the verbal exceptions with number values between 10 and 20 to the console */
void handle_teens(int teen) {
	
	switch (teen) {
		case 0:
			printf("Ten");
			break;
		case 1:
			printf("Eleven");
			break;
		case 2:
			printf("Twelve");
			break;
		case 3:
			printf("Thirteen");
			break;
		case 4:
			printf("Fourteen");
			break;
		case 5:
			printf("Fifteen");
			break;
		case 6:
			printf("Sixteen");
			break;
		case 7:
			printf("Seventeen");
			break;
		case 8:
			printf("Eighteen");
			break;
		case 9:
			printf("Nineteen");
			break;
	}
	
}

/* Handles printing any double digits' tens-place verbal value to the console */
void handle_tens(int tens) {
	
	switch (tens) {
		case 1:
			// See handle_teens()
			//handle_teens(ones);
			break;
		case 2:
			printf("Twenty");
			break;
		case 3:
			printf("Thirty");
			break;
		case 4:
			printf("Forty");
			break;
		case 5:
			printf("Fifty");
			break;
		case 6:
			printf("Sixty");
			break;
		case 7:
			printf("Seventy");
			break;
		case 8:
			printf("Eighty");
			break;
		case 9:
			printf("Ninety");
			break;
			}
	
}


/* Returns: Non-zero based value for the count of digits in the supplied string */
int count_digits(char string[]) {
	
	// Variable to store the count of digits/characters in a stirng
	int digit_count = 0;
	
	for (int i = 0; i < sizeof(&string); i++) {
		
		// fgets retrieves the newline character as well, so we exclude this char from the digit_count
		if (string[i] == '\n') {
			//printf("final_count: %d\n", digit_count);
			break;
		}
		
		// If the statement above is false, there is a valid digit/character
		digit_count++;
		
	}
	
	return digit_count;
}
