/*  write a program that reads a file and then counts the
    number of lines in it. 2023-08-15   */

// TRY A COUPLE DIFFERENT METHODS FOR THIS - different versions in
	// methods and benchmark to see which works best (fastest + handles
// weird input best. stuff to try:
// 	- reading file in line by line using fscanf
// 	- reading file in char by char using fgetc
// 	- reading some of file into buffer then looping thru buffer w/
// 	  pointer dereferences

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define _TESTING
#undef _TESTING
#define BUFFER_SIZE 256

int readLines1(char fileName[])	{
	// read file into a buffer string and loop through with pointers	
    unsigned int count = 0;	
	char buffer[BUFFER_SIZE];
	
	int thisFile = open(fileName, O_RDONLY);
	unsigned short readSize;
	char* thisCharP;	
	char thisChar;

	while ((readSize = read(thisFile, buffer, sizeof(buffer)-1)) > 0)	{
		thisCharP = buffer;
	    buffer[readSize] = '\0'; //make sure string terminated in correct location
		while (thisCharP != NULL && (thisChar = *thisCharP) != '\0')	{ 
			if (thisChar == '\n') count++;
			thisCharP++;
		}
	}
	
	close(thisFile);
	return count;
} // end readLines1 function

int readLines2(char fileName[])	{
    unsigned int count = 0;
	FILE * thisFile = fopen(fileName, "r");
	char thisChar;

    if (thisFile == NULL)   {
        fprintf(stderr, "Error opening file %s\n", fileName);
        return -1;
    }

	while ((thisChar = fgetc(thisFile)) != EOF)	{
		if (thisChar == '\n') count++;
	}

	fclose(thisFile);
	return count;
} // end readLines2 function


int readLines3(char fileName[])  {
    unsigned int count = 0;
    FILE * thisFile = fopen(fileName, "r");

    if (thisFile == NULL)   {
        fprintf(stderr, "Error opening file %s\n", fileName);
        return -1;
    }
    // if this buffer is too small (e.g., if file has lines with >120 characters)
	// this throws a segfault - not sure how to really solve
	char thisLine[120];
	// this should use fgets w/ max of string size then sscanf
    while (fscanf(thisFile, "%s", thisLine))   {
        if (getc(thisFile) == EOF) break;   // unga bunga
		++count;
    }
    
    fclose(thisFile); 
    return count; 
} // end readLines3 funtion

int main(int argc, char *argv[])    {
	// still need to run benchmarks...
    int cCount = 0; // can't use unsigned since returning -ve for errors

    if (argc < 2)   {
        fprintf(stderr, "No arguments passed to program - aborting.\n");
        exit(8);
    } else    {   
        for (unsigned short i = 1; i < argc; ++i)   {
            cCount = readLines1(argv[i]); 
            if (cCount >= 0) printf("The number of lines in %s is %d\n", argv[i], cCount);
        }
    }
    
    return(0);
}
