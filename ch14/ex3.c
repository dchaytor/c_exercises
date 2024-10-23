/*  write a program that reads a file containing a list of numbers,
    and then writes two files, one with all numbers divisible by 3
    and another containing all the other numbers. 2023-08-16,
    updated 2024-10-21	*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[])   {
    // read in file supplied in command line argument
    
    if (argc < 2)   {
        // yeah this could be a more helpful error message, but you get what you pay for
        fprintf(stderr, "No arguments provided on command line; aborting program.\n");
        exit(8);   
    }

    FILE * inFile = fopen(argv[1], "r");    // this could be written to accept multiple arguments, but that's more time than i want to spend
    
    if (inFile == NULL) {
        fprintf(stderr, "Error: could not find file %s; aborting program.\n", argv[1]);
        exit(8);
    }

    char fp3 [100];	// assuming filename + extra chars aren't more than 100 chars long 
    char fpElse [100];

    sprintf(fp3, "%s_div3", argv[1]);
    sprintf(fpElse, "%s_non-div3", argv[1]);    

    FILE * outFileDiv3 = fopen(fp3, "w");
    FILE * outFileElse = fopen(fpElse, "w");

    if (outFileDiv3 == NULL || outFileElse == NULL) {
		fclose(inFile);
		
		if (NULL == outFileElse && NULL == outFileDiv3)	{
			fprintf(stderr, "Error saving to output files %s and %s; aborting program", fp3, fpElse);
		}	
		else if (NULL == outFileElse) {
			fclose(outFileDiv3); 
			fprintf(stderr, "Error saving to output file %s; aborting program\n", fpElse);
		}
	   	else {
			fclose(outFileElse);
        	fprintf(stderr, "Error saving to output file %s; aborting program\n", fpElse);
		}
        exit(8);
    }

    // assuming 1 number per line
    int numIn = 0;

 	while(fscanf(inFile, "%d", &numIn) != EOF)	{		
        if ((numIn % 3) == 0) {
            fprintf(outFileDiv3, "%d\n", numIn);
        } else  {
            fprintf(outFileElse, "%d\n", numIn);
        } 
    }

    // close all the files
    fclose(inFile);
    fclose(outFileDiv3);
    fclose(outFileElse);

    printf("Numbers divisible by 3 stored in %s\n", fp3);
    printf("Numbers not divisible by 3 stored in %s\n", fpElse);

    return 0;
}
