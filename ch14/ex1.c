/*  write a program that reads a file and then counts the
    number of lines in it. 2023-08-15   */

// should really be doing this as a bitstream --- re-read chapter and re-write

#include <stdio.h>
#include <stdlib.h>
#define _TESTING
#undef _TESTING

int readLines(char fileName[])  {
    FILE * thisFile = fopen(fileName, "r");

    if (thisFile == NULL)   {
        fprintf(stderr, "Error opening file %s\n", fileName);
        return -1;
    }
   
    // it's worse for memory to do this way, but if i read in 1 char at a time and look for NL or EOF that's a lot of comparisons    
    // if this buffer is too small (e.g., if file has lines with >120 characters) this prog throws a segfault - not sure how to 
	// handle input safely here, maybe should just wrap the whole thing in a try-catch but that also feels hacky 
	char thisLine[120];
    
    unsigned int count = 0;

    while (1)   {
        fscanf(thisFile, "%s", thisLine);           
        if (getc(thisFile) == EOF) break;   // unga bunga
        //if (thisLine[0] == EOF) break;   // unga bunga
        
		++count;
    }
    
    fclose(thisFile); 
    return count; 
} // end readLines funtion

int main(int argc, char *argv[])    {

    int cCount = 0; // can't use unsigned since returning -ve for errors
    //char [100] cFile; // not sure if i'll need a temp var with a typecast or not

    if (argc < 2)   {
        fprintf(stderr, "No arguments passed to program - aborting.\n");
        exit(8);
    } else    {   
        for (unsigned short i = 1; i < argc; ++i)   {
            cCount = readLines(argv[i]); 
            if (cCount >= 0) printf("The number of lines in %s is %d\n", argv[i], cCount);
        }
    }
    

    return(0);
}
