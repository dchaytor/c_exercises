/* ex15-3: write a program to sum the elements in an array.
 * optimize it. 	*/

#include <stdio.h>

int sumArray(int A[], int sizeA)	{
	int* pA = &A[0];
	if (pA == NULL) return -1;
	register int sum = 0;	
	while (pA < (A + sizeA))	{
		sum += *pA++;
	}
	return sum;
}

// i could make this more usable but why bother here
// like, could get user input from shell param or from scanf but eh
int main(void)	{
	int array[] = {1,2,13,234,14,13,12,3,4};
	
	printf("The sum of the array is %d\n", \
			sumArray(array, sizeof(array) / sizeof(array[0])));
	return 0;
}
