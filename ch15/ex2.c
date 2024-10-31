/* ex15-2: write a matrix multiply function. create a test program
 * that not only tests the function, but times it as well. optimize
 * it using pointers and determine the time savings.			*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int matMul(int rowA, int colA, int rowB, int colB, \
		int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB]);

int matMul_nonOpt(int rowA, int colA, int rowB, int colB, \
	   	int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB]);

int main(int argc, const int *argv[])	{
	// WRITE CODE TO ACCEPT OPTIONAL INPUT FILE (default to stdout)
	int s = 0;
	FILE* OUTFILE = stdout;	
	if (2 <= argc)	{
		OUTFILE = fopen(argv[1], 'r');
		if (NULL == OUTFILE)	{
			fprintf("Error: could not print to file %s; aborting program",
					argv[1]);
			exit(-1);
		}
	}

	// FILL OUT TEST CASES
	time_t *AB1_START, time_t *AB1_END;
	
	const int ROWS_A1 = 2;
	const int COLS_A1 = 2;
	const int ROWS_B1 = 2;
	const int COLS_B1 = 2;

	A1 = {
		[1, 2],
		[5, 6]
	};
	B1 = {
		[3, 3],
		[9, 4]
	};
	int AB1[ROWS_A1][COLS_B1];
	
	// timing non-optimal function
	prefix = "non-";
	time(AB1_START);
	s = matMul_nonOpt(ROWS_A1, COLS_A1, ROWS_B1, COLS_B1, A1, B1, AB1);
	time(AB1_end);
	goto PRINT_MSG;		// print message out w/ current variables


	// timing optimal function
	prefix[0] = '\0';
	time(AB1_start);
	s = matMul(ROWS_A1, COLS_A1, ROWS_B2, COLS_B2, A1, B1, AB1);
	time(AB1_end);
	goto PRINT_MST;

	return 0;
}

PRINT_MSG:
	fprintf(OUTFILE, "Results of %soptimal matrix multiplication:\n",\
		   	prefix);
	goto PRINT_MATRIX; // print matrix out w/ current variables
	fprintf(OUTFILE, "\n");
	return;

PRINT_MATRIX:
	// size a new char matrix based on the height of the output
	// matrix (since should be the biggest) and the width of all
	// three matrices + room for brackets, whitespace, math
	// notation, and a column of \n chars at the end


	// loop through matrices separately (trusting it's sized properly)
	// assigning the appropriate chars in output matrix (print('0'+int) 

	
	// go through matrix in order (column > row, use ptr) and print
	// char to output file
	
	
	return;

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
