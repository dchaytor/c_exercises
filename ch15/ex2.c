/* ex15-2: write a matrix multiply function. create a test program
 * that not only tests the function, but times it as well. optimize
 * it using pointers and determine the time savings.			*/

/* NOTE: assuming 2D array with space already allocated			*/ 
int matrixMultiply(int rowA, int colA, int rowB, int colB, \
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
	register int* rpA = &A[0][0];
//	register int* cpA = rAp; // i don't think i need this since looping through
//	A in col then row (should be sequential, just ++ in both loops)
	register int* rpB = &B[0][0];
	register int* cpB = rpB;	
	register int* ABp = &AB[0][0];
		
	for (; rpA <= &A[rowA][0]; ++rpA)	{
		// go though outer loop of B with one pointer (cpB++), then
		// inner loop iterate other pointer (rpB++), then at start of loop
		// set rpB = cpB
	}	

	return 0;
}


int matrixMultiply_unoptimized(int rowA, int colA, int rowB, int colB, \
	   	int A[rowA][colA], int B[rowB][colB], intAB[rowA][colB])	{
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
