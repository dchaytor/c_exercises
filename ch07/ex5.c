/******************************************
 *  program to check if number is prime
 * 
 *  usage:
 *      type in a positive  number, program 
 *      will tell  you if it's prime. 
 *      enter 0 to exit
 *
 *
 *  retrictions:
 *      negative numbers not handled
 * 
 * 
 * 
 * 
 * 
 * 
 ******************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()  {
    unsigned int num_in = 0, max_divisor;   // number to be read in, as well as last number to check if prime
    short unsigned int i;
    bool prime;
    
    while (1)  {
        prime = true;

        printf("enter a postive whole number (or press 0 to exit):\t");
        scanf("%u", &num_in);

        if (num_in == 0) break;

        max_divisor = num_in / 2;
  
        if (max_divisor >= 2)    {
            
            for (i = 2; i <= max_divisor; ++i)   {
                if (num_in % i != 0)  {   // if doesn't go in evenly, might still be prime
                    continue;
                }
    
                prime = false;  // if program makes it past the if statement, number is not prime
                break;

            } // end for loop
        }        
    
        if (prime)  {
             printf("the number %u is prime.\n", num_in);
        } else  {
             printf("the number %u is not prime.\n", num_in);
        }

    } // end while loop     
    

    return (0);
}

