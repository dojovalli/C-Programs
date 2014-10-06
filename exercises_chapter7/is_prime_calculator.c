#include <stdio.h>

/* Function Declarations */
int is_prime(int number);
void program_purpose();
int prompt_user(char line[]);
void respond_to_user_request(int user_input);


int main(int argc, char *argv[]) {
	
	/* Hard Code testing 
	int test = 17;
	
	if (is_prime(test)) {
		printf("%d is a prime number.\n", test);
	} else {
		printf("%d is NOT a prime number.\n", test);
	}
	
	
	for (int i = 1; i < 10000; i++) {
		if (is_prime(i)) {
				printf("%d is a prime number.\n", i);
			}
	}
	*/
	
	// Program Variable
	char line[20];
	
	// Diplay the purpose of the program
	program_purpose();
	
	// Prompt the user for input, store the user input as an integer value
	int user_input = prompt_user(line);
	
	// Process the user-request
	respond_to_user_request(user_input);
	
	
}

/* Purpose: Checks to see if a number is prime.
 * Returns: 1 if the number is Prime, 0 if the number is not prime
 */
int is_prime(int number) {
	
	// is_prime is assumed to be true
	int is_prime = 1;
	
	// Test all Positive numbers
	// 'i' must start at 2 because all numbers are divisable by 1, even primes
	for (int i = 2; i < number; i++)                                      {
		
		// Variable to store the result of division
		int result = 0;
		
		// If the result does not have a remaining value, then the 'i' is a factor of 'number'
		result = number % i;
		
		if(result == 0) {
			// 'i' is a factor and 'number' is not prime
			is_prime = 0;
			//printf("%d is not a prime.", number);
			break;
		}
		
	}
	
	// Handle Exceptions
	if (number <= 1) {
		// 1 is not considered a prime, because it only has one factor (itself * itself)
		// 0 has an infinite number of factors resulting in zero, thus it is not prime
		// All negative numbers are not considered prime
		is_prime = 0;
	}
	
	return is_prime;
}

/* Purpose: States the purpose of the program */
void program_purpose() {
	// Print out the purpose of the program
	printf("This program tests to see if a number supplied by the user is prime or not.\n");
}

/* Purpose: Prompts the user for input.
 * Returns: Integer supplied by the user.
 */
int prompt_user(char line[]) {
			
			/* Local Temporary Vars */
			int user_input;
			
			/* Prompt user for first date */
			printf("Enter whole number: ");
			
				/* Read in the line from standard input */
				fgets(line, 100, stdin);
			
				/* Scan the string for integers */
				sscanf(line, "%d", &user_input);
				
		return user_input;
}


/* Purpose: Formats the output text for display to the user */
void respond_to_user_request(int user_input) {
	if (is_prime(user_input)) {
		printf("\n%d is a prime number.\n", user_input);
	} else {
		printf("\n%d is NOT a prime number.\n", user_input);
	}
}