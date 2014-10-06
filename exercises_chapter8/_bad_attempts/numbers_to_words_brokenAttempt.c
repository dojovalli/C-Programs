#include <stdio.h>
#include <string.h>
#include <math.h>

/* Functions */
void program_purpose();
void run_program();
int prompt_user();
void value_to_word(int input);
void handle_number(int number);
void handle_teens(int teen);
void handle_tens(int tens);
int count_digits(char string[]);
void method_by_digit(int number_of_digits, char string[]);
void handle_hundreds(int number);


/* Global Variables */
char line[100];
char output[1000];


int main(int argc, char *argv[]) {

	// Variable for user input
	int input;
	
	// State the purpose of the program
	program_purpose();
	
	/* Testing
	handle_tens(7);
	handle_number(4);
	handle_teens(5);
	*/
	
	
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
	
	/*
	// Convert the value to words
	value_to_word(user_input);
	
	// Print the output to the console
	printf("Verbal: %s", output);
	*/
	
	/* Alternative Approach
	int number_of_digits = count_digits(line);
	
	/method_by_digit(number_of_digits, line);
	
	// Display the final 'output' of the number to the user
	printf("%s", output);
	*/
	
	handle_hundreds(user_input);
}

void value_to_word(int input) {
	
	// Conditional
	int is_two_digit = (input >= 10) && (input < 100);
	int is_teen_exception = (input >= 10) && (input < 20);
	
	// If the input is zero, no need to run calculations
	if (input == 0) {
		strcat(output, "Zero");
		return;
	}
	
	/*
	// Get the count of digits so math can be done to adjust for multiple digits
	int digit_count = count_digits(line);
	
	// Debugging
	//printf("digit_count: %d\n", digit_count);
	*/
	
	handle_hundreds(input);
	
	
}

void handle_number(int number) {
	
	switch (number) {
			case 0:
				break;
			case 1:
				strcat(output, "One");
				printf("One");
				break;
			case 2:
				strcat(output, "Two");
				printf("Two");
				break;
			case 3:
				strcat(output, "Three");
				printf("Three");
				break;
			case 4:
				strcat(output, "Four");
				printf("Four");
				break;
			case 5:
				strcat(output, "Five");
				printf("Five");
				break;
			case 6:
				strcat(output, "Six");
				printf("Six");
				break;
			case 7:
				strcat(output, "Seven");
				printf("Seven");
				break;
			case 8:
				strcat(output, "Eight");
				printf("Eight");
				break;
			case 9:
				strcat(output, "Nine");
				printf("Nine");
				break;
		}
}

void handle_teens(int teen) {
	
	switch (teen) {
		case 0:
			strcat(output, "Ten");
			printf("Ten");
			break;
		case 1:
			strcat(output, "Eleven");
			printf("Ten");
			break;
		case 2:
			strcat(output, "Twelve");
			printf("Twelve");
			break;
		case 3:
			strcat(output, "Thirteen");
			printf("Thirteen");
			break;
		case 4:
			strcat(output, "Fourteen");
			printf("Fourteen");
			break;
		case 5:
			strcat(output, "Fifteen");
			printf("Fifteen");
			break;
		case 6:
			strcat(output, "Sixteen");
			printf("Sixteen");
			break;
		case 7:
			strcat(output, "Seventeen");
			printf("Seventeen");
			break;
		case 8:
			strcat(output, "Eighteen");
			printf("Eighteen");
			break;
		case 9:
			strcat(output, "Nineteen");
			printf("Nineteen");
			break;
	}
	
}

void handle_tens(int tens) {
	
	// Use the last character of the string 
	int last_index = (count_digits(line) - 2);
	int last_index_value;
	sscanf(&line[last_index], "%d", &last_index_value);
	//printf("last_index: %d\n", last_index);
	//printf("last_index_value: %d\n", last_index_value);
	 
	
	switch (tens) {
		case 1:
			// See handle_teens()
			handle_teens(last_index_value);
			break;
		case 2:
			strcat(output, "Twenty");
			printf("Twenty");
			break;
		case 3:
			strcat(output, "Thirty");
			printf("Thirty");
			break;
		case 4:
			strcat(output, "Forty");
			printf("Forty");
			break;
		case 5:
			strcat(output, "Fifty");
			printf("Fifty");
			break;
		case 6:
			strcat(output, "Sixty");
			printf("Sixty");
			break;
		case 7:
			strcat(output, "Seventy");
			printf("Seventy");
			break;
		case 8:
			strcat(output, "Eighty");
			printf("Eighty");
			break;
		case 9:
			strcat(output, "Ninety");
			printf("Ninety");
			break;
			}
		
		/*
		// Get the count of digits so math can be done to adjust for multiple digits
			int digit_count = count_digits(line);
			//printf("digit_count: %d\n", digit_count);
			
			if (line[digit_count - 1] != 0) {
				// Use hyphen to seperate second digit
				strcat(output,"-");
				printf("-");
			}
		*/
	
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


void method_by_digit(int number_of_digits, char string[]) {
	
	int rounds = number_of_digits;
	
	// Each round represents three digits
	while (rounds >= 0) {
		
		for (int i = 0; i < number_of_digits; i++) {
			
			//printf("For-loop: i = %d, casted-value: %d\n", i, string[i]);
			
			// Pull out the integer value for the character at the given string
			int integer;
			sscanf(&string[i], "%d", &integer);
			// Debugging
			//printf("integer: %d\n", integer);
			
			// Calculates the power of 10 used to divid by to retrieve the a single digit in any digit column, an additional 1 is subtracted because number_of_digits is not zero-based
			int digit_ratio = pow(10, (number_of_digits - 1 - i));
			int current_number = integer / digit_ratio;
			printf("current_number: %d\n", current_number);
			
			// Vocabulary is determined by Hundreds, Tens, and Ones
			switch ((number_of_digits - i) % 3) {
				case 0:
					/* Hundreds Column */
					handle_number(current_number);
					strcat(output, " Hundred ");
					break;
				case 1:
					/* Ones Column */
					handle_number(current_number);
					break;
				case 2:
					/* Tens */
					handle_tens(current_number);
			}
			
		}

		// NEED TO DETERMINE WHETHER: hundreds, thousands, millions, billions, trillions, etc.
		
		
		// Subtract Three digit places to decrease a round in the loop by one
		rounds -= 3;
	}
	
}

void handle_hundreds(int number) {

	// Number breakdown
	// Pull out the 
	int hundreds = number / 100;
	int tens = number / 10;
	int ones = number - (hundreds * 100) - (tens * 10);
	
	// Vocabulary is determined by Hundreds, Tens, and Ones
	if (hundreds != 0) {
		printf("%d Hundred", hundreds);
	}
	
	if (tens > 9) {
		
		if (hundreds > 0) {
			printf(" ");
		}
		
		handle_tens(tens);
	}
	
	if (ones != 0) {
		
		if (tens > 0) {
			printf("-");
		}
		
		handle_number(ones);
	}
			
}

/*
char final_string[] string_append(char appending_line[], char original_line[],int with_space) {
	
	int string_length = sizeof(appending_line) + sizeof(original_line) + with_space;
	char final_string[string_length];
	
	
	
	
	switch(with_space) {
		case 1:
			strcat(" ", original_line);
		case 0:
			strcat(appending_line, original_line);
	
}
*/