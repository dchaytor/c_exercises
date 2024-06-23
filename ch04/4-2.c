// ex2

#include <stdio.h>


int main()	{
	
	int width = 5;		// width of E
	int height = 7;		// height of E


	int i = 0;	// height indexing var

	while (i < height)	{
		int j = 0;	// width indexing var
		int n_ast = 1;	// number of asterisks to print on line

		if (i == 0 || i == (height-1))	{
			n_ast = width;

		} else if (i == height / 2)	{
			n_ast = width / 2 + 1;
			
		}

		while (j < n_ast)	{
			printf("*");
			j++;
		}	
		printf("\n");

		
		i++;
	}	



	return (0);
}
