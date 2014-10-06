#include <stdio.h>

/* Functions */
void program_purpose();
void run_program();
int prompt_user();
void determine_room(int available_rooms);
int prompt_size_of_room();
void single_ac_room();


/* Global Variables */
char line[10];
const int double_room = 1;
const int twin_room = 2;
const int triple = 3;


int main(int argc, char *argv[]) {
	
	// State the Purpose of the Program and print to console
	program_purpose();
	
	// Run the program
	run_program();
	
}

void program_purpose() {

	printf("This program determines the which rooms Liz and Aaron will stay in at Don Det, Loas.\n\n");
	
}

void run_program() {
	
	// Prompt the user for input
	int available_ac_rooms = prompt_user();
	
	// Determine which rooms the users will stay in
	determine_room(available_ac_rooms);
	
}

int prompt_user() {
	
	// Variable for return value
	int available_rooms;
	
	// Prompt the user for input
	printf("Input the number of rooms available with AC: ");
	
	// Retrieve the input from the user
	fgets(line, sizeof(line), stdin);
	
	// Convert String value into an integer
	sscanf(line, "%d", &available_rooms);
	
	return available_rooms;
}

void determine_room(int available_rooms) {

/*	
	if (available_rooms >= 2) {
		printf("Erin and Liz will both stay in an AC room.");
	} else if(available_rooms == 1) {
		
		if (number_of_beds == double_room) {
			printf("One will stay in a fan room and the other will stay in a AC room");		} else {
			printf("Both will stay in a AC room.");
			}
		
	} else {
		printf("Both will stay in a fan room.");
	}
*/
	if (available_rooms != 1) {
		// New line for formatting answer
		printf("\n");
	}
	
	switch (available_rooms) {
		case 0:
			printf("Both will stay in a fan room.");
			break;
		case 1:
			single_ac_room();
			break;
		
		default:
			printf("Erin and Aaron will both stay in an AC room.");
			break;
			
	}
	
	
}

int prompt_size_of_room() {
	
		// Return Var
		int number_of_beds;
		
		// Prompt the user for input
		printf("Input the number of beds in AC Room: ");
				
		// Retrieve the input from the user
		fgets(line, sizeof(line), stdin);
				
		// Convert String value into an integer
		sscanf(line, "%d", &number_of_beds);
		
	return number_of_beds;
}

void single_ac_room() {
			
	// Prompt the user for the number of beds available in the roo
	int number_of_beds = prompt_size_of_room();
			
	// New line for formatting answer
	printf("\n");		
	
	if (number_of_beds == double_room) {
		printf("One will stay in a fan room and the other will stay in a AC room.");	} else {
		printf("Both will stay in a AC room.");
	}
}