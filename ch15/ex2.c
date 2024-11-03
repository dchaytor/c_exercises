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
#include <string.h>

#define ROWS_A1 2
#define COLS_A1 2
#define ROWS_B1 2
#define COLS_B1 2

int matMul(int rowA, int colA, int rowB, int colB, \
		int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB]);

int matMul_nonOpt(int rowA, int colA, int rowB, int colB, \
	   	int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB]);
void PRINT_MATRIX(FILE* OUTFILE, int ROWS_A, int COLS_A, \
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

	int A1[ROWS_A1][COLS_A1] = { \
		{1, 2},
		{5, 6}
	};
	int B1[ROWS_B1][COLS_B1] = { \
		{3, 3},
		{9, 4}
	};
	int AB1[ROWS_A1][COLS_B1];

	// timing non-optimal function
	time(&AB_START);
	s = matMul_nonOpt(ROWS_A1, COLS_A1, ROWS_B1, COLS_B1, A1, B1, AB1);
	time(&AB_END);
	fprintf(OUTFILE, "Results of optimal matrix multiplication:\n");
	PRINT_MATRIX(OUTFILE, ROWS_A1, COLS_A1, ROWS_B1, COLS_B1,\
		   	A1, B1, AB1);
	fprintf(OUTFILE, "Time elapsed: %ds\n\n", (int)(AB_END-AB_START));
	
	// timing optimal function
	time(&AB_START);
	s = matMul(ROWS_A1, COLS_A1, ROWS_B1, COLS_B1, \
			&A1[0][0], &B1[0][0], &AB1[0][0]);
	time(&AB_END);
	fprintf(OUTFILE, "Results of optimal matrix multiplication:\n");
	printf("%p\n", A1);
	printf("%d\n", A1[0][0]);
	fflush(stdout);
	PRINT_MATRIX(OUTFILE, ROWS_A1, COLS_A1, ROWS_B1, COLS_B1, \
			&A1[0][0], &B1[0][0], &AB1[0][0]);
	fprintf(OUTFILE, "Time elapsed: %ds\n\n", (int)(AB_END-AB_START));
	
	return s;
}


// THIS SUCKS, but i'm not sure of good way to do this!
void PRINT_MATRIX(FILE* OUTFILE, int ROWS_A, int COLS_A, \
		int ROWS_B, int COLS_B, int* pA, int* pB, int* pAB)	{
	// getting size of printout, assigning pointers/matrix ints
	int PRINTROWS = (ROWS_A > ROWS_B ? ROWS_A : ROWS_B);
	int PRINTCOLS = COLS_A + 2*COLS_B + 10;

	printf("%p\n", pA);
	printf("%d\n", *pA);
	fflush(stdout);
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
}

/* NOTE: assuming 2D array with space already allocated			*/ 
int matMul(int rowA, int colA, int rowB, int colB, \
		int A[rowA][colA], int B[rowB][colB], int AB[rowA][colB])	{
	// check for errors in input
	if (colA != rowB) {
		fprintf(stderr, "ERROR: matrix multiplication requires the number of rows in matrix B to equal the columns of rows in matrix A.\n");
		return -1;
	}
	if (sizeof(A)*sizeof(A[0]) < sizeof(int) * rowA * colA || \
			sizeof(B)*sizeof(B[0]) < sizeof(int) * rowB * colB)	{
		fprintf(stderr, "ERROR: size of provided matrix does not match input row and column values\n");
		return -1;		
	}
	
	// loop through and do matrix multiplication
	int* cpA = &A[0][0];		// col pointer for A
	int* cpB = &B[0][0];		// row pointer for B
	int* rpB = cpB;			// column pointer for B	
	int* ABp = &AB[0][0];		// index pointer for AB
	memset(&AB[0][0], 0, sizeof(AB));

	// loop through rows of A (ptr on last col from inner loop)	
	for (; cpA <= &A[rowA][0]; cpA++)	{
		// loop through cols of B
		for (; cpB <= &B[0][colB]; cpB++)	{
			// w/ separate ptr, go thru rows of B for current col
			for (rpB=cpB; rpB<=cpB+colB*(rowB-1); rpB+=colB)	{
				*ABp +=  *rpB * *cpA;
				++cpA; 
			}
			ABp++;
		}
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

	if (sizeof(A)*sizeof(A[0]) < sizeof(int) * rowA * colA || \
			sizeof(B)*sizeof(B[0]) < sizeof(int) * rowB * colB)	{
		fprintf(stderr, "ERROR: size of provided matrix does not match input row and column values\n");
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
