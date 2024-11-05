/* ex15-4: write a program that counts the number of bits in a
 * character array. optimize it through the use of register 
 * integer variables. time it on several different arrays of
 * different sizes. how much time do you save?		*/

#include <stdio.h>

// note: counting the \0 char since it takes up space in the string
int getNumBits(char str[])	{
	char* pS = &str[0];
	if (pS == NULL) return 0;
	register int cSize = sizeof(*pS) * 8;	// assuming 8 bit bytes
	register int nBits = cSize;
	while (*pS++ != '\0') 	nBits += cSize;
	return nBits;
}

int main(void)	{
	char str[] = "test!"; // should be (5 + 1) * 8 = 48
	printf("Number of bits in test string: %d\n", getNumBits(str));
	return 0;
}
