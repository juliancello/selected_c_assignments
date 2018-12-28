/* Julian Kosanovic
11/21/2018
Pointers assignment

This program will:
- Ask user for number of questions to be in the quiz
- Generate a quiz with n questions
- Allocates memory dynamically for storing the following:
	- 2 arrays for each of operands (use rand() to generate random 2 digit numbers
	- 1 array for storing user answers
	- 1 array for storing correct answers
- Present score card
- Free up dynamically allocated memory
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand ((unsigned int)time(NULL)); //Make rand() spawn more random numbers 
	int n; //number of questions to take
	int *userAns;	
	int *correctAns;
	int *op1;
	int *op2;
	//char *result; // Not using this. I don't know why it is necessary
	int *result; //a dynamic array of 0s (incorrect) and 1s (correct) to represent answers
	int numCorrectAns;
	float score;

	printf("Addition Quiz\n\n");
	printf("Enter in number of problems you would like in this quiz: "); //Prompt user for how many questions in the quiz
	scanf("%d", &n);
	op1 = (int*)calloc(n, sizeof(int)); //calloc(number of items, sizeof(data type));
	op2 = (int*)calloc(n, sizeof(int));
	correctAns = (int*)calloc(n, sizeof(int));
	userAns = (int*)calloc(n, sizeof(int));
	result = (int*)calloc(n, sizeof(int));
	// Generate quiz with n questions using calloc 
	for (int i=0; i<n; i++) // Generate 2 arrays n length using rand(), calloc and for loops
	{
		op1[i]= rand() % 90 + 10;
		op2[i]= rand() % 90 + 10;
		correctAns[i]=op1[i] + op2[i]; // Generate 1 array for storing correct answers obtained from performing operations on 
		printf("\n%d + %d = ", op1[i], op2[i]); //Prompt user for answer
		scanf("%d", &userAns[i]); // Generate 1 array for storing user answers
		if (correctAns[i] == userAns[i]){
			result[i]=1;
			++numCorrectAns;
		}
		
		else{
			result[i]=0;
		}
	}
	printf("Quiz Results:\n\n");
	printf("%s %15s %10s\n", "Question", "Your Answer", "Correct");//"Question%25s,Your Answer%25s,Correct");
	for (int i=0;i<n;i++)
	{
		printf("%d + %d %8d", op1[i], op2[i], userAns[i]);
		if (result[i]==1)
		{
			printf("%15s\n", "Yes");
		}
		else
		{
			printf("%15s\n","No");
		}
	}
	for (int i=0;i<50;++i)
	{
		printf("=");
	}
	score = (float)numCorrectAns/(float)n *100;
	printf("\nYour score is %d / %d -> %.2f %% \n", numCorrectAns, n, score);
	for (int i=0;i<50;++i)
	{
		printf("=");
	}
	printf("\n");
	
	free(userAns); //Free up dynamic memory
	free(correctAns);
	free(op1);
	free(op2);
	free(result);
	userAns=0;
	correctAns=0;
	op1=0;
	op2=0;
	result=0;
	
	return 0;
}
	














