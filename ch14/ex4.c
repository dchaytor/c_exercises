/*  ch14-ex4: write a program that reads an ascii file containing 
 *  a list of numbers and writes a binary file containing
 *  the same list. write a program that goes the other way so 
 *  that you can check your work  */

// going to just do this as one program but use a command line 
// argument to decide if it's bin-asc or asc-bin

#include <stdio.h>
#include <stdlib.h>

int bin2asc(FILE* inFile, FILE* outFile)	{
	// read file into buffer as binary, output to outFile as ascii
	// probably just use getc and putc; don't do own buffer
	
	return 0;
}

int asc2bin(FILE* inFile, FILE* outFile)	{
	// read file into buffer as ascii, output to outFile as bin
	// probably just use getc and putc; don't do own buffer

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
		fname++
	}
	return 0;	// no extension found in string
}

int main(int argc, char * argv[])   {
    char _bin2asc = 'n';    
	FILE* inFile, outFile;	
	
    // being kind of lazy about how i handle this - not doing a 
	// verbose error message since I'm the only one using this, 
	// and not bothering to handle multiple file inputs
    switch (argc)   {
        case 0: // shouldn't be possible, but just in case
        case 1:
        case 2:
            fprintf(stderr, "Error: not enough arguments passed to command line.\n");
            printf("Usage: ./ex4 [FILE]inFile [b]inary_output/[a]scii_output");
			exit(8);
			break;
		case 3:
            if (argv[argc - 1][0] == 'a') _bin2asc = 'y';
			break;
		default:
            fprintf(stderr, "Error: too many arguments passed to command line.\n");
            printf("Usage: ./ex4 [FILE]inFile [b]inary_output/[a]scii_output");
			exit(8);
            break;
    }
  
   	// i may be stupid	
	char* fileNameNoExtn = (char*)malloc(sizeof(argv[1]));
	char* fileName = argv[1]; 
	while (*fileNameNoExtn++ == *fileName++) 
	if (-1 == _rm_extension(&fileNameNoExtn))	{
		fprintf(stderr, "Error: could not process file name. Aborting.\n");
		free(fileNameNoExtn);
		exit(4);	
	} // after this, should have fileName == file.ext and fileNameNoExtn == file 

   	if ('y' == _bin2asc)	{
		inFile = fopen(fileName, "rb");
		outFile = fopen(strcat(fileNameNoExtn, "_ascii.DAT"), 
	}	else	{
		inFile = fopen(argv[1], "r");
		outFile = fopen(strcat(fileNameNoExtn, "_binary.BIN"), "wb");
	}

	free(fileNameNoExtn);

    if (NULL == inFile || NULL == outFile)	 {
        fprintf(stderr, "Error: could not find file %s; aborting program\n", argv[1]);
        exit(2);
    }
 
   		
    if (_bin2asc == 'n') 



    return 0;}
