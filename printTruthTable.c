/* Julian Kosanovic
12/3/2018
Bitwise assignment
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0, sizeTable;
	char **truthTable;
	do {
		printf("Enter a set size between 1 and 10 to generate the truth table combination of: ");
		scanf("%d",&n);
	} while (n <= 0 || n > 10);
	
	sizeTable = 2 << (n-1);

	truthTable = malloc(sizeof(char*) * sizeTable);

	printf("Here are your %d T/F combinations for a set size of %d:\n", sizeTable, n);
	
	for (int i=0;i<sizeTable;i++) // should run 2^n times
	{
		for (int j=0;j<n;j++) //should run n times 
		{
			if (i & 1 << j){ 
				truthTable[i] = "T";
			}
			else{
				truthTable[i] = "F"; 
			}
			printf("%s",truthTable[i]);
		}
		printf("\n");
	
	}
	free(truthTable);
	return 0;
}















