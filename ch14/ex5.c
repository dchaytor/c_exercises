/*	ex 14-5: write a program that copies a file and removes all
 *	characters with the high bit set ((ch & 0x80) != 0)		*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MASKBIT 0x80

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

int main(int argc, char ** argv)	{
	// make sure input correct; put error message otherwise
	if (argc != 2)	{
		fprintf(stderr, "ERROR: incorrect number of input arguments specified; aborting execution.\n");
		printf("Usage: ./ex5 FILE_IN\n");
		exit(8);
	}

	char* const inFName = argv[1];
	char* const outFName = (char*)malloc(sizeof(char) * \
			strlen(inFName) + 15); 	// allocating extra bytes for extn
	if (NULL == outFName)	{
		fprintf(stderr, "Could not assign memory for output file handle; aborting program.\n");
		exit(9);
	}

	char* s = inFName; char* t = outFName;	
	while (*t++ = *s++) ;

	if (-1 == _rm_extension(outFName))	{
		fprintf(stderr, "Error: could not process output file name. Aborting.\n");
		free(outFName);
		exit(4);	
	} // should have inFName == file.ext and outFName == file 
	// doesn't make sense to open as ascii-  ascii will never have hi bit set
	FILE* inFile = fopen(inFName, "rb");
	FILE* outFile = fopen(strcat(outFName, "_NoChar0x80.bin"), "wb"); 

    if (NULL == inFile || NULL == outFile)	 {
		if (NULL == inFile && NULL == outFile)	{
			fprintf(stderr, "Error opening input file %s and output file %s; aborting.\n", inFName, outFName);
		} else if (NULL == inFile)	{
			fclose(outFile);
			fprintf(stderr, "Error opening input file %s; aborting.\n", \
					inFName);
		} else	{
			fclose(inFile);
			fprintf(stderr, "Error opening outout file %s; aborting.\n", \
					outFName);
		}	
		free(outFName);
		exit(2);
    }
	
	char cChar;
	while (0 != fread(&cChar, 1, sizeof(cChar), inFile))	{
		if ((cChar & MASKBIT) == 0) fwrite(&cChar, 1, sizeof(cChar), outFile);
	}

	fprintf(stdout, "Copied contents of %s without 0x%x set to %s\n", \
			inFName, MASKBIT, outFName);
	fclose(inFile);
	fclose(outFile);
	free(outFName);
	return 0;
}
