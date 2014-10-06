#include <stdio.h>

/* Functions */
void program_purpose();
void prompt_user();
int is_vowel(char character);
int is_consinent(char character);

/* Global Variables */
char line[2]; /* Only a single character and the EOL '\0' need to be stored */
char character;

int main(int argc, char *argv[]) {
	
	// Prompt the user with the purpose of the program
	program_purpose();
	
	// Prompt the user of input
	prompt_user();
	
	// Debugging
	// printf("Character: %s\n", &character);
	
	if (is_vowel(character)) {
		printf("The character %s is a vowel.", &character);
	} else if (is_consinent(character)) {
		printf("The character %s is a consinent.", &character);
	} else {
		printf("The character %s is not a vowel or a consinent.", &character);
	}
	
}


void program_purpose() {
	
	printf("This program informs the user whether the character is a vowel or a consinent.\n");
	printf("This program will only test the first character input by the user, all other characters are ignored.\n\n");
	
}

void prompt_user() {
	// Temporary Variables
	float user_input;

	// Prompt User for input
	printf("Enter a single character: ");
	
	// Get the user input
	fgets(line, sizeof(line), stdin);
	
	// Parse the line for a float number
	sscanf(line, "%s", &character);
}



int is_vowel(char character) {
	
	// '1' if true, '0' if false
	int is_vowel = 0;
	
	switch (character) {
		
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				is_vowel = 1;
				break;
				
		default:
				is_vowel = 0;
			break;
	}
	
	return is_vowel;
}

int is_consinent(char character) {
	
	// '1' if true, '0' if false
	int is_consinent = 0;
	
	/* Conditional Math - if the character is between these ASCII values and they aren't
	 * vowels then they are consinents.
	 */ 
	int is_cons_lower = (character >= 'a' && character <= 'z') && !(is_vowel(character));
	int is_cons_upper = (character >= 'A' && character <= 'Z') && !(is_vowel(character));
	
	if (is_cons_lower || is_cons_upper) {
		// printf("This logic worked.\n");
		is_consinent = 1;
	}

	return is_consinent;
}