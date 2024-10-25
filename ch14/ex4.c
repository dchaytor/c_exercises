/*  ch14-ex4: write a program that reads an ascii file containing 
 *  a list of numbers and writes a binary file containing
 *  the same list. write a program that goes the other way so 
 *  that you can check your work  */

// going to just do this as one program but use a command line 
// argument to decide if it's bin-asc or asc-bin

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int asc2bin(FILE* inFile, FILE* outFile)	{
	if (NULL == inFile || NULL == outFile)	return 1;

	int thisInt = '\0';
	while ((thisInt = getw(inFile)) != EOF) {
		fwrite(&thisInt, 1, sizeof(thisInt), outFile); 
	}
	return 0;
}

int bin2asc(FILE* inFile, FILE* outFile)	{
	if (NULL == inFile || NULL == outFile)	return 1;

	int thisInt = '\0';
	while (fread(&thisInt, 1, sizeof(thisInt), inFile) != 0)	{
		putw(thisInt, outFile); 
	}
	return 0;
}

int _rm_extension(char* fname)	{
	if (NULL == fname) return -1;	// passed in null ptr; exit
	
	char thisChar;	
	while ('\0'	!= (thisChar = *fname))	{
		if (thisChar == '.')	{
			*fname = '\0';
			return 1; 	// found extension in string
		}	
		fname++;
	}
	return 0;	// no extension found in string
}

int main(int argc, char * argv[])   {
    char _opfmt = 'n';    
	FILE* inFile; FILE* outFile;	
	
    switch (argc)   {
        case 0: // shouldn't be possible, but just in case
        case 1:
        case 2:
            fprintf(stderr, "Error: not enough arguments passed to command line.\n");
            printf("Usage: ./ex4 [FILE]inFile [b]inary_output/[a]scii_output\n");
			exit(8);
			break;
		case 3:
			_opfmt = argv[argc - 1][0];
			if (_opfmt != 'a' && _opfmt != 'b')	{
            	fprintf(stderr, "Error: invalid argument supplied to program.\n");
            	printf("Usage: ./ex4 [FILE]inFile [b]inary_output/[a]scii_output\n");
				exit(8);
			}
			break;
		default:
            fprintf(stderr, "Error: too many arguments passed to command line.\n");
            printf("Usage: ./ex4 [FILE]inFile [b]inary_output/[a]scii_output\n");
			exit(8);
            break;
    }
  
   	// i may be stupid	
	char* const fileName = argv[1];
	char* const outputFileName = (char*)malloc(sizeof(char) * \
			strlen(fileName) + 15); 	// allocating 15 extra bytes for extension
	if (NULL == outputFileName)	{
		fprintf(stderr, "Could not assign memory; aborting program.\n");
		exit(9);
	}

	char* s = fileName; char* t = outputFileName;	
	while (*t++ = *s++) ;		// should copy string

	if (-1 == _rm_extension(outputFileName))	{
		fprintf(stderr, "Error: could not process file name. Aborting.\n");
		free(outputFileName);
		exit(4);	
	} // after this, should have fileName == file.ext and fileNameNoExtn == file 

   	if ('a' == _opfmt)	{
		inFile = fopen(fileName, "rb");
		outFile = fopen(strcat(outputFileName, "_ascii.DAT"), "w"); 
	}	else	{
		inFile = fopen(fileName, "r");
		outFile = fopen(strcat(outputFileName, "_binary.BIN"), "wb");
	}

    if (NULL == inFile || NULL == outFile)	 {
		if (NULL == inFile && NULL == outFile)	{
			fprintf(stderr, "Error opening input file %s and output file %s; \
					aborting.\n", fileName, outputFileName);
		} else if (NULL == inFile)	{
			fclose(outFile);
			fprintf(stderr, "Error opening input file %s; aborting.\n", \
					fileName);
		} else	{
			fclose(inFile);
			fprintf(stderr, "Error opening outout file %s; aborting.\n", \
					outputFileName);
		}	
		free(outputFileName);
		exit(2);
    }
	
	unsigned short int exitCode = 0;
	// i think i'm going to have to check the _bin2asc condition again... sucks, but
	// other way is repeating a bunch of code 
    if ('a' == _opfmt)	exitCode = bin2asc(inFile, outFile);
	else	exitCode = asc2bin(inFile, outFile);	

	printf("Successfully wrote contents of %s to %s\nExit: %d\n", fileName, \
			outputFileName, exitCode); 

	// close files, free memory
	free(outputFileName);
	fclose(inFile);
	fclose(outFile);
    
	return exitCode;
}
