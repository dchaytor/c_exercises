/*  write a program that reads an ascii file containing a list of numbers and writes a binary file containing
    the same list. write a program that goes the other way so that you can check your work  */


#include <stdio.h>
#include <stdlib.h>

// going to just do this as one program but use a command line arguement to decide if it's bin-asc or asc-bin

int main(int argc, char * argv[])   {
    char _bin2asc = 'n';    

    // being kind of lazy about how i handle this - not doing a verbose error message since I'm the only one
    // using this, and not bothering to handle multiple file inputs
    switch (argc)   {
        case 0: // shouldn't be possible, but just in case
        case 1:
            fprintf(stderr, "Error: not enough arguments passed to command line.\n");
            exit(8);
            break;
        case 2:
           break; 
        default:
            if (argv[argc - 1][0] == 'b') _bin2asc = 'y';
            break;
    }
    
    FILE * inFile = fopen(argv[1], "r");

    if (inFile == NULL) {
        fprintf(stderr, "Error: could not find file %s; aborting program\n", argv[1]);
        exit(8);
    }
  
    // not sure if can read in data all at once or have to do line-by-line
    // if doing line-by-line, read in a string with fgets or something then output as either bin or ascii
    // prob should do line-by-line for memory reasons - full file would be a pretty big buffer 
    if (_bin2asc == 'n')    {

    } else  {


    }        

    return 0;
}
