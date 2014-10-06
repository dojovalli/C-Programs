#include <stdio.h>
#include <math.h>

/* */
char line[100];
char line2[100];

/* Point 1 */
float x_1;
float y_1;

/* Point 2 */
float x_2;
float y_2;


/* Trig Vars */
float x_diff;
float y_diff;
float distance_between_points;

int main(int argc, char *argv[]) {
	
	printf("This program calculates the distance between two points\n");
		
		/* Ask the user for the height of the rect */
		printf("Enter Point 1 (x,y): ");
		
			/* Get the users input */
			fgets(line, sizeof(line), stdin);
		
			/* Pull out the float value stored in the string */
			sscanf(line, "(%f, %f)", &x_1, &y_1);
		
		/* Ask the user for the height of the rect */
		printf("Enter Point 1 (x,y): ");
				
			/* Get the users input */
			fgets(line2, sizeof(line2), stdin);
				
			/* Pull out the float value stored in the string */
			sscanf(line2, "(%f, %f)", &x_2, &y_2);
	
	/* Calculations */
	x_diff = x_1 - x_2;
	y_diff = y_1 - y_2;
	
	distance_between_points = hypot(x_diff,y_diff);
	
	printf("Point 1: (%f, %f)\n", x_1, y_1);
	printf("Point 2: (%f, %f)\n", x_2, y_2);
	printf("Distance between points: %f units", distance_between_points);
	
	
	
	
	
}