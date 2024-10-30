/* ex15-2: write a matrix multiply function. create a test program
 * that not only tests the function, but times it as well. optimize
 * it using pointers and determine the time savings.			*/

#include <stdlib.h>

int matMul(int rowA, int colA, int rowB, int colB, \
		int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB]);

int matMul_nonOpt(int rowA, int colA, int rowB, int colB, \
	   	int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB]);

int main()	{
	// FILL OUT TEST CASES


	return 0;
}
	
/* NOTE: assuming 2D array with space already allocated			*/ 
int matMul(int rowA, int colA, int rowB, int colB, \
		int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB])	{
	// check for errors in input
	if (col != rowB) {
		fprintf("ERROR: matrix multiplication requires the number of rows in matrix B to equal the columns of rows in matrix A.");
		return -1;
	}

	if (sizeof(A) < sizeof(int) * rowA * colA || \
			sizeof(B) < sizeof(int) * rowB * colB)	{
		fprintf("ERROR: size of provided matrix does not match input row and column values");
		return -1;		
	}
	
	// loop through and do matrix multiplication
	register int* cpA = &A[0][0];		// col pointer for A
	register int* cpB = &B[0][0];		// row pointer for B
	register int* rpB = cpB;			// column pointer for B	
	register int* ABp = &AB[0][0];		// index pointer for AB
	memset(&AB[0][0], 0, rowA * colB * sizeof(AB[0][0]));

	// loop through rows of A (ptr on last col from inner loop)	
	for (; cpA <= &A[rowA][0]; cpA++)	{
		// loop through cols of B
		for (; cpB <= &B[0][colB]; cpP++)	{
			// w/ separate ptr, go thru rows of B for current col
			for (rpB=cpB; rpB<=cpB+colB*(rowB-1); rpP+=colB)	{
				&ABp +=  &rpB * &cpA;
				++cpA; 
			}
			&ABp++;
		}
	}	
	return 0;
}


int matMul_nonOpt(int rowA, int colA, int rowB, int colB, \
	   	int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB])	{
		// check for errors in input
	if (colA != rowB) {
		fprintf("ERROR: matrix multiplication requires the number of columns in matrix B to equal the number of rows in matrix A.");
		return -1;
	}

	if (sizeof(A) < sizeof(int) * rowA * colA || \
			sizeof(B) < sizeof(int) * rowB * colB)	{
		fprintf("ERROR: size of provided matrix does not match input row and column values");
		return -1;		
	}
	
	int elsum = 0;
	// loop through rows of matrix A
	for (int aj = 0; aj < rowA; ++aj)	{
		// loop through cols of matrix B	
		for (int bi = 0; bi < colB; ++bi)	{
			elsum = 0;
			// loop through	cols of A/rows of B
			for (int ai = 0; ai < colA; ++ai)	{
				elsum += A[aj][ai] * B[ai][bi];
			}	
			AB[aj][bi] = elsum;
		}
	}		

	return 0;
}
