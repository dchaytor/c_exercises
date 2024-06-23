/*  write a program that reads a file containing a list of numbers,
    and then writes two files, one with all numbers divisible by 3
    and another containing all the other numbers. 2023-08-16    */

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

    char fp3 [100]; 
    char fpElse [100];

    sprintf(fp3, "%s_div3", argv[1]);
    sprintf(fpElse, "%s_non-div3", argv[1]);    

    FILE * outFileDiv3 = fopen(fp3, "w");
    FILE * outFileElse = fopen(fpElse, "w");

    if (outFileDiv3 == NULL || outFileElse == NULL) {
        fprintf(stderr, "Error saving to output files; aborting program\n");
        exit(8);
    }


    // assuming 1 number per line
    int numIn = 0;

    while(!feof(inFile))    {
        //numIn = getw(inFile); // this wasn't working properly; kept reading ascii or something idk
        fscanf(inFile, "%d", &numIn);
        
        if ((numIn % 3) == 0) {
            //putw(numIn, outFileDiv3);
            fprintf(outFileDiv3, "%d\n", numIn);
        } else  {
            //putw(numIn, outFileElse);
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
