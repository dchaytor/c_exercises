/* ex15-2: write a matrix multiply function. create a test program
 * that not only tests the function, but times it as well. optimize
 * it using pointers and determine the time savings.		
 *
 * ASSUMPTIONS:
 * - matrices are using integer values only
 * - matrix elements are <=999 (affects printout only)
 * */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int matMul(int rowA, int colA, int rowB, int colB, \
		int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB]);

int matMul_nonOpt(int rowA, int colA, int rowB, int colB, \
	   	int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB]);

int main(int argc, const char *argv[])	{
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

	time_t *AB_START, time_t *AB_END;

	// defining pointers for tracking printout
	int *pA, int *pB, int *pAB;
	int COLS_A, int ROWS_A, int COLS_B, int ROWS_B;

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
	int AB[ROWS_A1][COLS_B1];

	// getting size of printout, assigning pointers/matrix ints
	int PRINTROWS = (ROWS_A1 > ROWS_B1 ? ROWS_A1 : ROWS_B1);
	int PRINTCOLS = COLS_A1 + 2*COLS_B1 + 10;
	COLS_A = COLS_A1, ROWS_A = ROWS_A1;
	COLS_B = COLS_B1, ROWS_B = ROWS_B1;

	// timing non-optimal function
	prefix = "non-";
	pA = A1, pB = B1, pAB = AB1;	// reset printout ptrs
	time(AB_START);
	s = matMul_nonOpt(ROWS_A1, COLS_A1, ROWS_B1, COLS_B1, A1, B1, AB1);
	time(AB_END);
	goto PRINT_MSG;		// print message out w/ current variables

	// timing optimal function
	prefix[0] = '\0';
	pA = A1, pB = B1, pAB = AB1;	// reset printout ptrs
	time(AB_START);
	s = matMul(ROWS_A1, COLS_A1, ROWS_B1, COLS_B1, A1, B1, AB1);
	time(AB_END);
	goto PRINT_MSG;		// print message out w/ current variables

	return 0;
}

PRINT_MSG:
	fprintf(OUTFILE, "Results of %soptimal matrix multiplication:\n",\
		   	prefix);
	goto PRINT_MATRIX; // print matrix out w/ current variables
	fprintf(OUTFILE, "Time elapsed: %ds\n\n", (int)(AB_END-AB_START));
	return;

PRINT_MATRIX:
	// THIS SUCKS, but i'm not sure of good way to do this!
	// for loop conditions would be tough to read otherwise	
	short A_STARTCOL = 0;	// left bracket for A
	short A_ENDCOL = A_STARTCOL + COLS_A + 1; // A right brack
	short B_STARTCOL = A_ENDCOL + 1;	// B left brack
	short B_ENDCOL = B_STARTCOL + COLS_B + 1; // B right brack 
	short AB_STARTCOL = B_ENDCOL + 2;	// AB left brack
	short AB_ENDCOL = PRINTCOLS - 2;	// AB right brack 
	short A_STARTROW = (PRINTROWS - ROWS_A) / 2;
	short A_ENDROW = A_STARTROW + COLS_A; 
	short B_STARTROW = (PRINTROWS - ROWS_B) / 2;
	short B_ENDROW = B_STARTROW + COLS_B;

	for (int i = 0; i < PRINTCOLS; ++i)	{
		for (int j = 0; j < PRINTROWS; ++j)	{
			// i'd love to use a switch here, but need ranges
			if (i == A_STARTCOL)	{	// A left brack
				if (j <= A_STARTROW && j > A_ENDROW)	{
					fprintf(OUTFILE, "[");
				} else fprintf(OUTFILE, " ");
			}
			else if (i < A_ENDCOL)	{	// A matrix 
				if (j <= A_STARTROW && j > A_ENDROW)	{
					fprintf(OUTFILE, "%4d", *pA++);
				} else fprintf(OUTFILE, "    ");
			}	
			else if (i == A_ENDCOL)	{	// A right brack
				if (j <= A_STARTROW && j > A_ENDROW)	{
					fprintf(OUTFILE, "]");
				} else fprintf(OUTFILE, " ");
			}
			else if (i == B_STARTCOL)	{	// B left brack
			   if (j <= B_STARTROW && j > B_ENDROW)	{
					fprintf(OUTFILE, "[");
			   } else fprintf(OUTFILE, " ");
			}	   
			else if (i < B_ENDCOL)	{	// B matrix 
				if (j <= B_STARTROW && j > B_ENDROW)	{
					fprintf(OUTFILE, "%4d", *pB++);
				} else fprintf(OUTFILE, "    ");
			}	
			else if (i == B_ENDCOL)	{	// B right brack
				if (j <= B_STARTROW && j > B_ENDROW)	{
					fprintf(OUTFILE, "]");
				} else fprintf(OUTFILE, " ");
			}
			else if (i == B_ENDCOL + 1)	{ // equal sign
				if (j == PRINTROWS / 2)	{
					fprintf(OUTFILE, "=");
				} else fprintf(OUTFILE, " ");
			}
			else if (i == AB_STARTCOL)	{ // AB left brack
				if (j <= A_STARTROW && j > A_ENDROW)	{
					fprintf(OUTFILE, "[");
				} else fprintf(OUTFILE, " ");
			}
			else if (i < AB_ENDCOL)	{	// AB matrix
				if (j <= A_STARTROW && j > A_ENDROW)	{
					fprintf(OUTFILE, "%4d", *pAB++);
				} else fprintf(OUTFILE, "    ");
			}
			else if (i == AB_ENDCOL)	{ // AB right brack
				if (j <= A_STARTROW && j > A_ENDROW)	{
					fprintf(OUTFILE, "]");
				} else fprintf(OUTFILE, " ");
			}
			else fprintf(OUTFILE, "\n");
		}
	}
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
