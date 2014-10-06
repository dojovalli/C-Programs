/* By: Matthew Valli
 * Purpose: Calculates the change to return to a customer when given a total value to return
 */

#include <stdio.h>
#include <string.h>

/* Variables */
char line[100]; /* array of characters for input */
float total_cash_value; /* given cash value */
int remaining_cash_value; /* convert cash into int */

/* Tender Notes/Bills (USA) */
int hundred_bill; /* stores the ammount of 100 dollar bills to return as change */
int fifty_bill; /* stores the ammount of 50 dollar bills to return as change */
int twenty_bill; /* stores the ammount 20 twenty dollar bills to return as change */
int ten_bill; /* stores the ammount of 10 dollar bills to return as change */
int five_bill; /* stores the ammount of 5 dollar bills to return as change */
int one_bill; /* stores the ammount of 1 dollar bills to return as change */

/* Tender Coin (USA) */
int fifty_coin; /* stores the ammount of $0.50 coin to return as change */
int quarter; /* stores the ammount of $0.25 coin to return as change */
int dime; /* stores the ammount of $0.10 coin to return as change */
int nickel; /* stores the ammount of $0.05 coin to return as change */
int penny; /* stores the ammount of $0.01 coin to return as change */

int main(int argc, char *argv[]) {
	
	printf("This program calculates the change to return to a customer.\n");
	
	/* Ask the user for the value of change to return */
	printf("Enter the total value of cash to return ($1.37 should be formatted 1.37): ");
	
	/* Get the users input */
	fgets(line, sizeof(line), stdin);
	
	/* Pull out the float value stored in the string */
	sscanf(line, "%f", &total_cash_value);
	
	/* Convert cash into an integer */
	remaining_cash_value = (int) (total_cash_value * 100); /* multiplying by 100 changes the dollars into cents */
	
	/* Testing Log Statements
	printf("total_cash_value: %f\n", total_cash_value);
	printf("remaining_cash_value: %d\n", remaining_cash_value);
	*/
	
	
	/* Run the conversion */
	if (remaining_cash_value >= 10000) {
		/* Determine number of bills of this value to return */
		hundred_bill = remaining_cash_value / 10000;
		/* Determine the remaining value of change left for calculating change */
		remaining_cash_value %= 10000;
	}
	if (remaining_cash_value >= 5000) {
			/* Determine number of bills of this value to return */
			fifty_bill = remaining_cash_value / 5000;
			/* Determine the remaining value of change left for calculating change */
			remaining_cash_value %= 5000;
		}
	if (remaining_cash_value >= 2000) {
			/* Determine number of bills of this value to return */
			twenty_bill = remaining_cash_value / 2000;
			/* Determine the remaining value of change left for calculating change */
			remaining_cash_value %= 2000;
		}
	if (remaining_cash_value >= 1000) {
			/* Determine number of bills of this value to return */
			ten_bill = remaining_cash_value / 1000;
			/* Determine the remaining value of change left for calculating change */
			remaining_cash_value %= 1000;
		}
	if (remaining_cash_value >= 500) {
			/* Determine number of bills of this value to return */
			five_bill = remaining_cash_value / 500;
			/* Determine the remaining value of change left for calculating change */
			remaining_cash_value %= 500;
		}
	if (remaining_cash_value >= 100) {
			/* Determine number of bills of this value to return */
			one_bill = remaining_cash_value / 100;
			/* Determine the remaining value of change left for calculating change */
			remaining_cash_value %= 100;
		}
	if (remaining_cash_value >= 50) {
			/* Determine number of bills of this value to return */
			fifty_coin = remaining_cash_value / 50;
			/* Determine the remaining value of change left for calculating change */
			remaining_cash_value %= 50;
		}	
	if (remaining_cash_value >= 25) {
				/* Determine number of bills of this value to return */
				quarter = remaining_cash_value / 25;
				/* Determine the remaining value of change left for calculating change */
				remaining_cash_value %= 25;
			}
	if (remaining_cash_value >= 10) {
				/* Determine number of bills of this value to return */
				dime = remaining_cash_value / 10;
				/* Determine the remaining value of change left for calculating change */
				remaining_cash_value %= 10;
			}
	if (remaining_cash_value >= 5) {
				/* Determine number of bills of this value to return */
				nickel = remaining_cash_value / 5;
				/* Determine the remaining value of change left for calculating change */
				remaining_cash_value %= 5;
			}
	if (remaining_cash_value >= 1) {
				/* Determine number of bills of this value to return */
				penny = remaining_cash_value / 1;
				/* Determine the remaining value of change left for calculating change */
				remaining_cash_value %= 1;
			}
	
	
	printf("\n");
	
	/* Display the result to the user */
	printf("$100 = %d\n", hundred_bill);
	printf("$50 = %d\n", fifty_bill);
	printf("$20 = %d\n", twenty_bill);
	printf("$10 = %d\n", ten_bill);
	printf("$5 = %d\n", five_bill);
	printf("$1 = %d\n", one_bill);
	printf("$0.50 = %d\n", fifty_coin);
	printf("$0.25 = %d\n", quarter);
	printf("$0.10 = %d\n", dime);
	printf("$0.05 = %d\n", nickel);
	printf("$0.01 = %d\n", penny);
	
	return(0);
}