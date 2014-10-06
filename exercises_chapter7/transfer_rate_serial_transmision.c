#include <stdio.h>
#include <math.h>

/* Functions */
void program_purpose();
void prompt_user(char line[]);
int convert_input_to_bytes(char line[]);
int transform_string_to_byte_factor(char string[]);
int time_of_transfer(int total_bytes);
void format_time_output(int seconds);


/* Global Vars */
const int SERIAL_BPS = 960;
const int SECONDS_IN_MINUTE = 60;
const int MINUTES_IN_HOUR = 60;
const int HOURS_IN_DAY = 24;
const int DAYS_IN_WEEKS = 7;
const int WEEKS_IN_YEAR = 52;

const int YEAR_IN_SECONDS = SECONDS_IN_MINUTE * MINUTES_IN_HOUR * HOURS_IN_DAY * DAYS_IN_WEEKS * WEEKS_IN_YEAR;
const int WEEK_IN_SECONDS = SECONDS_IN_MINUTE * MINUTES_IN_HOUR * HOURS_IN_DAY * DAYS_IN_WEEKS;
const int DAY_IN_SECONDS = SECONDS_IN_MINUTE * MINUTES_IN_HOUR * HOURS_IN_DAY;
const int HOUR_IN_SECONDS = SECONDS_IN_MINUTE * MINUTES_IN_HOUR;

int main(int argc, char *argv[]) {

	// Program Vars
	char user_input[20];
	
	// Display the purpose of the program
	program_purpose();
	printf("%s", user_input);
	
	// Prompt the user, convert the input and store the converted input in a variable
	prompt_user(user_input);
	
	// Run conversion of string input into an integer representing bytes
	int total_bytes = convert_input_to_bytes(user_input);
	
	// Calculate the time it would take to transfer a given ammount of bytes (in seconds)
	int seconds = time_of_transfer(total_bytes);
	
	// Output the results in a Human-Readable form
	format_time_output(seconds);
	
	
}

/* Purpose: States the purpose of the program */
void program_purpose() {
	// Print out the purpose of the program
	printf("This program calculates the time it takes to send a file over serial transmission line.\n");
}

/* Purpose: Prompts the user for input.
 * Returns: Integer supplied by the user.
 */
void prompt_user(char line[]) {
			
			/* Prompt user for first date */
			printf("Enter file size: ");
			
			/* Read in the line from standard input */
			fgets(line, 100, stdin);
				
}

/* Purpose: Converts a string into an actual numberic value of bytes, attributing data portion abbrivations
 * Returns: Integer representing the total bytes supplied by the user
 */
int convert_input_to_bytes(char line[]) {
	
	int byte_quantity;
	char byte_size[3];
	
	/* Scan the string for integers */
	sscanf(line, "%d%s", &byte_quantity, &byte_size);
	
	int byte_factor = transform_string_to_byte_factor(byte_size);
					
	int converted_input = byte_quantity * byte_factor;
					
	return converted_input;
}

/* Purpose: Transforms user input of data portion abbriviations into actual numeric figures
 * Returns: A byte factor is returned that can be used to calculate the exact number of bytes in the file
*/
int transform_string_to_byte_factor(char string[]) {
	
	// If the user enters in bytes without a string representation, the byte_factor is 1
	int byte_factor = 1;
	
	// Get the first letter out of the given string
	char byte_size = string[0];
	
	switch (byte_size) {
		case 'k':
		case 'K':
			byte_factor = pow(2,10);
			break;
		case 'm':
		case 'M':
			byte_factor = pow(2,20);
			break;
		case 'g':
		case 'G':
			byte_factor = pow(2,30);
			break;
		case 't':
		case 'T':
			byte_factor = pow(2,40);
		
		default:
			byte_factor = 1;
			break;
	}
	
	printf("byte_factor: %d\n", byte_factor);
	
	return byte_factor;
}

/* Purpose: Convert the number of bytes to the number of seconds it take to make a transfer over a Serial Transmission
 * Return: Integer representing seconds
*/
int time_of_transfer(int total_bytes) {
	
	int seconds = total_bytes / SERIAL_BPS;
	
	return seconds;
}

/* Purpose: Formats the output text based on the supplied number of seconds */
void format_time_output(int seconds) {
	
	printf("Transfer time (%d seconds): ", seconds);
	
	// Calculate Years
	int years = seconds / (SECONDS_IN_MINUTE * MINUTES_IN_HOUR * HOURS_IN_DAY * DAYS_IN_WEEKS * WEEKS_IN_YEAR);
	// Calculate Weeks, subtracting previously calculated time
	int weeks = (seconds - (years * YEAR_IN_SECONDS)) / (SECONDS_IN_MINUTE * MINUTES_IN_HOUR * HOURS_IN_DAY * DAYS_IN_WEEKS);
	// Calculate Days, subtracting previously calculated time
	int days = (seconds - (years * YEAR_IN_SECONDS) - (weeks * WEEK_IN_SECONDS)) / (SECONDS_IN_MINUTE * MINUTES_IN_HOUR * HOURS_IN_DAY);
	// Calculate Hours, subtracting previously calculated time
	int hours = (seconds - (years * YEAR_IN_SECONDS) - (weeks * WEEK_IN_SECONDS) - (days * DAY_IN_SECONDS)) / (SECONDS_IN_MINUTE * MINUTES_IN_HOUR);
	// Calculate Minutes, subtracting previously calculated time
	int minutes = (seconds - (years * YEAR_IN_SECONDS) - (weeks * WEEK_IN_SECONDS) - (days * DAY_IN_SECONDS) - (hours * HOUR_IN_SECONDS)) / (SECONDS_IN_MINUTE);
	// Calculate the remaining seconds, subtracting previously calculated time
	int remaining_seconds = seconds % 60;
	
	// If the time is more than a year, report the time including the years
	if (years > 1){
		printf("%d years ", years);
	} else if (years == 1) {
		printf("%d year ", years);
	}
	
	// If the time is more than a week, report the time including the weeks
	if (weeks > 1){
		printf("%d weeks ", weeks);
	} else if (weeks == 1) {
		printf("%d week ", weeks);
	}
	
	// If the time is more than a day, report the time including the days
	if (days > 1){
		printf("%d days ", days);
	} else if (days == 1) {
		printf("%d day ", days);
	}
	
	// If the time is more than a hour, report the time including the hours
	if (hours > 1){
		printf("%d hours ", hours);
	} else if (hours == 1) {
		printf("%d hour ", hours);
	}
	
	// If the time is more than a minute, report the time including the minutes
	if (minutes > 1){
		printf("%d minutes ", minutes);
	} else if (minutes == 1) {
		printf("%d minute ", minutes);
	}
	
	// If the time is more than a second, report the time including the seconds
	if (remaining_seconds > 1) {
		printf("%d seconds ", remaining_seconds);
	} else if (remaining_seconds == 1) {
		printf("%d second ", remaining_seconds);
	}
}