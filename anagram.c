/* Kosanovic, Julian
Assignment: Anagrams (week 6)
Date: 10/29/18

Notes: This assignment will prompt the user for 2 strings, check if the two strings are anagrams (case sensitive),
print the result along with the input strings. This program has the option to repeat until the user quits (any other
character other than Y or y).
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int true = 1; 
int false = 0; 

int main(void)
{
	printf("\nTitle: Anagram checking program\n");
	printf("Author: Julian Kosanovic\n\n");
	while(true)
	{
		char str1[50], str2[50], x[50], y[50], t[50], z[50], choice;
		int k, mindex, j, i;
	
		printf("Please enter a string:\n"); // prompt for string 1
		fgets(str1, 50, stdin); //gets input from user and stores it in char array str1 without having to explicitly loop

		printf("Please enter another string:\n"); // prompt for string 2
		fgets(str2, 50, stdin); // gets input from user and stores it in char array str2

		j=0;
		for (int i = 0; i<49; i++) // converts to lower case and stores in separate array to be further manipulated
		{
			if (str1[i] != ' ') //ignore any whitespace when transferring to new array
			{
				x[j]=tolower(str1[i]); //new array all lower case
				++j;
			}
		}
		j=0;
		for (int i = 0; i<49; i++) // same to str2
		{
			if (str2[i] != ' ')
			{
				y[j]=tolower(str2[i]);
				++j;
			}
		}

		for (i=0;i<49;i++) // loop through up to max chars for first string
		{
			if ((int)x[i+1]<96) //if any characters that less than 'a' ascii value, break loop and move on
			{	
				break;
			}
			for (j=0;j<49;j++) 
			{
				if ((int)x[j+1]<96) //if any characters that less than 'a' ascii value, break loop and move on
				{	
					break;
				}
				if ((int)x[j]>(int)x[j+1]) //switch adjacent letters
				{
					t[j]=x[j];
					x[j]=x[j+1];
					x[j+1]=t[j];
				}
			}
		}
		j=0;
		for (i=0;i<49;i++) // loop through up to max chars for second string
		{
			if ((int)y[i+1]<96)
			{	
				break;
			}
			for (j=0;j<49;j++)
			{
				if ((int)y[j+1]<96)
				{	
					break;
				}
				if ((int)y[j]>(int)y[j+1])
				{
					z[j]=y[j];
					y[j]=y[j+1];
					y[j+1]=z[j];
				}
			}
		}
	

		k = strcmp(x, y); //compare strings 

		printf("The strings\n\t");
		puts(str1);
		printf("\n\t");
		puts(str2);
	
	
		if (k==0) //if strings are the same (anagrams)
		{
			printf("are anagrams.\n");
		}
		else
		{
			printf("are not anagrams.\n");
		}
		printf("Do you want to continue? (Hit Y to continue) "); //run program again?
		scanf("%c%*c", &choice);
		choice=tolower(choice);
		if (choice == 'y')
		{
			continue;
		}
		else
		{
			return false;
		}
	 }
}










