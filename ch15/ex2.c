/* ex15-2: write a matrix multiply function. create a test program
 * that not only tests the function, but times it as well. optimize
 * it using pointers and determine the time savings.		
 *
 * ASSUMPTIONS:
 * - matrices are using integer values only
 * - matrix intput elements are <=99 (affects printout only)
 * */

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS_A1 2
#define COLS_A1 2
#define ROWS_B1 2
#define COLS_B1 2

#define ROWS_A2 3
#define COLS_A2 6
#define ROWS_B2 6
#define COLS_B2 5

int matMul(int rowA, int colA, int rowB, int colB, \
		int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB]);

int matMul_nonOpt(int rowA, int colA, int rowB, int colB, \
	   	int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB]);
void PRINT_MATMUL(FILE* OUTFILE, int ROWS_A, int COLS_A, \
		int ROWS_B, int COLS_B, int* pA, int* pB, int* pAB);
	
int main(int argc, const char *argv[])	{
	// WRITE CODE TO ACCEPT OPTIONAL INPUT FILE (default to stdout)
	int s = 0;
	FILE* OUTFILE = stdout;	
	if (2 <= argc)	{
		OUTFILE = fopen(argv[1], "r");
		if (NULL == OUTFILE)	{
			fprintf(stderr, "Error: could not print to file %s; aborting program",
					argv[1]);
			exit(-1);
		}
	}

	time_t AB_START; time_t AB_END;

	// 2x2 matrix test case
	int A1[ROWS_A1][COLS_A1] = { \
		{1, 2},
		{5, 6}
	};
	int B1[ROWS_B1][COLS_B1] = { \
		{3, 3},
		{9, 4}
	};
	int AB1[ROWS_A1][COLS_B1];

	// more complicated matrix test case
	int A2[ROWS_A2][COLS_A2] = { \
		{2, 6, 3, 1, 3, 6},
		{3, 1, 6, 4, 3, 2},
		{3, 5, 6, 2, 3, 3}
	};	
	int B2[ROWS_B2][COLS_B2] = { \
		{5, 1, 4, 3, 1},
		{2, 3, 2, 1, 5},
		{9, 7, 7, 4, 1},
		{3, 7, 8, 4, 3},
		{4, 3, 5, 1, 2},
		{3, 4, 2, 7, 3}
	};
	int AB2[ROWS_A2][COLS_B2];

	// timing non-optimal function on 2x2 test case
	time(&AB_START);
	s += matMul_nonOpt(ROWS_A1, COLS_A1, ROWS_B1, COLS_B1, A1, B1, AB1);
	time(&AB_END);
	fprintf(OUTFILE, "Results of non-optimal matrix multiplication:\n");
	PRINT_MATMUL(OUTFILE, ROWS_A1, COLS_A1, ROWS_B1, COLS_B1, A1, B1, AB1);
	fprintf(OUTFILE, "Time elapsed: %fs\n\n", (float)(AB_END-AB_START));
	
	// timing optimal function on 2x2 test case
	time(&AB_START);
	s += matMul(ROWS_A1, COLS_A1, ROWS_B1, COLS_B1, A1, B1, AB1);
	time(&AB_END);
	fprintf(OUTFILE, "Results of optimal matrix multiplication:\n");
	PRINT_MATMUL(OUTFILE, ROWS_A1, COLS_A1, ROWS_B1, COLS_B1, A1, B1, AB1);
	fprintf(OUTFILE, "Time elapsed: %fs\n\n", (float)(AB_END-AB_START));
	
	// timing non-optimal function on more complex test case
	time(&AB_START);
	s += matMul_nonOpt(ROWS_A2, COLS_A2, ROWS_B2, COLS_B2, A2, B2, AB2);
	time(&AB_END);
	fprintf(OUTFILE, "Results of non-optimal matrix multiplication:\n");
	PRINT_MATMUL(OUTFILE, ROWS_A2, COLS_A2, ROWS_B2, COLS_B2, A2, B2, AB2);
	fprintf(OUTFILE, "Time elapsed: %fs\n\n", (float)(AB_END-AB_START));
	
	// timing optimal function on more complex test case
	time(&AB_START);
	s += matMul(ROWS_A2, COLS_A2, ROWS_B2, COLS_B2, A2, B2, AB2);
	time(&AB_END);
	fprintf(OUTFILE, "Results of optimal matrix multiplication:\n");
	PRINT_MATMUL(OUTFILE, ROWS_A2, COLS_A2, ROWS_B2, COLS_B2, A2, B2, AB2);
	fprintf(OUTFILE, "Time elapsed: %fs\n\n", (float)(AB_END-AB_START));
	
	return s;
}

/* NOTE: assuming 2D array with space already allocated			*/ 
int matMul(int rowA, int colA, int rowB, int colB, \
		int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB])	{
	// check for errors in input
	if (colA != rowB) {
		fprintf(stderr, "ERROR: matrix multiplication requires the number of rows in matrix B to equal the columns of rows in matrix A.\n");
		return -1;
	}

	// null pointer check:
	if (NULL == A || NULL == B || NULL == AB) return -1;

	// loop through and do matrix multiplication
	int* cpA = &A[0][0];		// col pointer for A
	int* cpB = &B[0][0];		// row pointer for B
	int* rpB = cpB;				// column pointer for B	
	int* ABp = &AB[0][0];		// index pointer for AB

	// loop through A in sequence (go thru cols, then fall thru to next row) 
	while (cpA <= &A[rowA-1][colA-1])	{
		// loop through cols of B
		for (cpB = &B[0][0]; cpB <= &B[0][colB-1]; cpB++)	{
			*ABp = 0;
			// w/ separate ptr, go thru rows of B for current col
			for (rpB = cpB; rpB <= cpB + (colB)*(rowB-1); rpB += colB)	{
				*ABp += *rpB * *cpA;
				++cpA;
			}
			++ABp;
			cpA -= colA;
		}
		cpA += colA;
	}	
	return 0;
}

int matMul_nonOpt(int rowA, int colA, int rowB, int colB, \
	   	int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB])	{
		// check for errors in input
	if (colA != rowB) {
		fprintf(stderr, "ERROR: matrix multiplication requires the number of columns in matrix B to equal the number of rows in matrix A.\n");
		return -1;
	}
	
	// null pointer check:
	if (NULL == A || NULL == B || NULL == AB) return -1;
	
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

// THIS SUCKS, but i'm not sure of good way to do this!
void PRINT_MATMUL(FILE* OUTFILE, int ROWS_A, int COLS_A, \
		int ROWS_B, int COLS_B, int* pA, int* pB, int* pAB)	{

	// computing column bounds
	short A_STARTCOL = 0;	// left bracket for A
	short A_ENDCOL = A_STARTCOL + COLS_A + 1; // A right brack
	short B_STARTCOL = A_ENDCOL + 1;	// B left brack
	short B_ENDCOL = B_STARTCOL + COLS_B + 1; // B right brack 
	short AB_STARTCOL = B_ENDCOL + 2;	// AB left brack
	short AB_ENDCOL = AB_STARTCOL + COLS_B + 1;	// AB right brack 
	
	// getting overall  size of printout
	short PRINTROWS = (ROWS_A > ROWS_B ? ROWS_A : ROWS_B);
	short PRINTCOLS = AB_ENDCOL + 1; // don't really need but a lil clearer

	// computing row bounds
	short A_STARTROW = (PRINTROWS - ROWS_A) / 2;
	short A_ENDROW = A_STARTROW + ROWS_A; 
	short B_STARTROW = (PRINTROWS - ROWS_B) / 2;
	short B_ENDROW = B_STARTROW + ROWS_B;

	for (int j = 0; j < PRINTROWS; ++j)	{
		for (int i = 0; i < PRINTCOLS; ++i)	{
			// i'd love to use a switch here, but need ranges
			if (i == A_STARTCOL)	{	// A left brack
				if (j >= A_STARTROW && j < A_ENDROW)	{
					fprintf(OUTFILE, "[");
				} else fprintf(OUTFILE, " ");
			}
			else if (i < A_ENDCOL)	{	// A matrix	
				if (j >= A_STARTROW && j < A_ENDROW)	{
					fprintf(OUTFILE, "%3d", *pA++);
				} else fprintf(OUTFILE, "   ");
			}	
			else if (i == A_ENDCOL)	{	// A right brack
				if (j >= A_STARTROW && j < A_ENDROW)	{
					fprintf(OUTFILE, "]");
				} else fprintf(OUTFILE, " ");
			}
			else if (i == B_STARTCOL)	{	// B left brack
			   if (j >= B_STARTROW && j < B_ENDROW)	{
					fprintf(OUTFILE, "[");
			   } else fprintf(OUTFILE, " ");
			}	   
			else if (i < B_ENDCOL)	{	// B matrix 
				if (j >= B_STARTROW && j < B_ENDROW)	{
					fprintf(OUTFILE, "%3d", *pB++);
				} else fprintf(OUTFILE, "   ");
			}	
			else if (i == B_ENDCOL)	{	// B right brack
				if (j >= B_STARTROW && j < B_ENDROW)	{
					fprintf(OUTFILE, "]");
				} else fprintf(OUTFILE, " ");
			}
			else if (i == B_ENDCOL + 1)	{ // equal sign
				if (j == PRINTROWS / 2 - 1)	{
					fprintf(OUTFILE, " = ");
				} else fprintf(OUTFILE, "   ");
			}
			else if (i == AB_STARTCOL)	{ // AB left brack
				if (j >= A_STARTROW && j < A_ENDROW)	{
					fprintf(OUTFILE, "[");
				} else fprintf(OUTFILE, " ");
			}
			else if (i < AB_ENDCOL)	{	// AB matrix
				if (j >= A_STARTROW && j < A_ENDROW)	{
					fprintf(OUTFILE, "%5d", *pAB++);
				} else fprintf(OUTFILE, "     ");
			}
			else if (i == AB_ENDCOL)	{ // AB right brack
				if (j >= A_STARTROW && j < A_ENDROW)	{
					fprintf(OUTFILE, "]");
				} else fprintf(OUTFILE, " ");
			}
		}
		fprintf(OUTFILE, "\n");
	}
	return;
}
