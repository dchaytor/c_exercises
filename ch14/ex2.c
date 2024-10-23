/* write a program to copy a file, expanding all tabs to multiple spaces */

#define NUM_SPACES 2	// would normally do 4 but want it to be easily visible

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// probably want to just read in file, then write char by char to another
// destination file, checking character for tab -> if char read is tab, 
// don't write to file but instead write number of spaces

int main(int argc, char* argv[])	{

	/*  could write this to accept number of spaces as optional param
	 *  but that seems like a lot of extra work for a practice problem
	 *  given that it isn't really the point of the exercise			*/

	// want to allow usage "copy_spaces source dest" as well as just accepting
	// "copy_spaces source", which would just assign a default to dest
	FILE * inFile;
	FILE * outFile;

	switch(argc)	{
		case 0:		// shouldn't be possible, but just in case
		case 1:		// no command line arguments passed
		case 2:
			fprintf(stderr, "ERROR: insufficient arguments supplied; aborting");
			exit(8);
		//case 2:		// no output file specified; create new one
			/* this was causing problems when file had extention (e.g., .c);
			 * would create file, but wouldn't write to it properly; could get
			 * around this by parsing thru argv[1] string, look for '.' char, and
			 * if exists, return string with characters preceeding the '.' (if not
			 * found, would just return original string), but this seems very extra
			 * for this practice problem (would have to either look for cstd lib func
			 * or create function that creates a new string with malloc)	
			*/
		//	outFile = fopen(strcat(argv[1], "!"), "w");	
		// 	break;
		default:
			outFile = fopen(argv[2], "w");
	}
	
	inFile = fopen(argv[1], "r");

	// it's more annoying to do this way, but giving error message for
	// failing to open outfile before error for infile is kind of weird
	if (NULL == inFile || NULL == outFile)	{
		if (NULL == inFile && NULL == outFile)	{
			fprintf(stderr, "Error opening input and output files; aborting program\n");
		} else if (NULL == inFile)	{
			fprintf(stderr, "Error opening input file; aborting program\n");
			fclose(outFile);
		} else	{
			fprintf(stderr, "Error opening output file; aborting program\n");
			fclose(inFile);
		}
		exit(8);
	}

	char thisChar;
	while (EOF != (thisChar = fgetc(inFile)))	{
		if ('\t' == thisChar)	{	
			for (int idx = 0; idx < NUM_SPACES; idx++)	{
				fputc(' ', outFile); 
			}
		} else fputc(thisChar, outFile);
	}

	fclose(inFile);
	fclose(outFile);
	return(0);
}
