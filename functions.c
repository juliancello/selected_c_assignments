/* 
Title: Functions Assignment
Author: Julian Kosanovic, intro written by Instructor Kavita Nautiyal
Date: 11/4/18

Notes: 
*/


#include <stdio.h>

/* FUNCTION PROTOTYES */
void LineBreak();
void WelcomeMessage();
void AskUserForInput();
void PrintTripSummary(float fuel, float minCost, float maxCost, float travelMiles); 

void LineBreak(){
	for (int i=0;i<=70;i++)
	{
		printf("*");
	}
	printf("\n\n");
}

void WelcomeMessage(){
	printf("\n");
	LineBreak();
	printf("Welcome to the Trip Planner!\n\nThis program helps you figure out how much money you need to budget for gas.\n\n");
	printf("This program is intended for the use in locations that use the imperial system and the United States Dollar.\n\n");
	LineBreak();
	
}
void AskUserForInput(){ /* ask and check whether user wants to continue
                            if wants to continue gather information 
                            and calculate the results (optional create more functions)
                            */
	float fuel, minCost, maxCost, travelMiles;
	
	while (fuel != 0){
		printf("Please enter in your car's average miles per gallon (enter 0 to quit program) >> ");
		scanf("%f",&fuel);
		if (fuel == 0){
			break;
		}
		printf("\nPlease tell me the range of fuel costs you expect to pay (per gallon).\n\n");
		printf("The lowest cost per gallon expected >> ");
		scanf("%f",&minCost);
		printf("\nThe highest cost per gallon expected >> ");
		scanf("%f",&maxCost);
		printf("\nHow many miles do you plan on traveling? >> ");
		scanf("%f",&travelMiles);
		printf("\n");
		fuel = travelMiles/fuel; //turns mpg into how much fuel for this trip
		minCost = minCost * fuel; //turns min price per gallon into min price per trip
		maxCost = maxCost * fuel; //turns max price per gallon into max price per trip
		PrintTripSummary(fuel, minCost, maxCost, travelMiles);
	}
	
}
                            
void PrintTripSummary(float fuel, float minCost, float maxCost, float travelMiles){
                            /* could call this from AskUserForInput(); 
                            In a loop and feed it the user input
                            */
	for (int i=0;i<=20;i++){
		printf("*");
	}
	printf(" Trip summary ");
	for (int i=0;i<=20;i++){
		printf("*");
	}
	printf("\n\nYou will need to purchase %.2f gallons of fuel.\n", fuel);
	printf("\nThe approximate cost for fuel for your trip is between $%.2f and $%.2f.\n\n", minCost, maxCost);
	for (int i=0;i<=20;i++){
		printf("*");
	}
	printf(" End of Trip summary ");
	for (int i=0;i<=20;i++){
		printf("*");
	}
	printf("\n\n");
} 

/* MAIN */

int main() {
	printf("\nFunctions Assignment\n");
	printf("Author: Julian Kosanovic\n\n");

	/* Call the functions */
	// car's average mpg
	//low cost per gallon
	//high cost per gallon
	//trip length
	//how many gallons to purchase
	//cost range
	WelcomeMessage();
	AskUserForInput();
	printf("\n");
	return 0;

}