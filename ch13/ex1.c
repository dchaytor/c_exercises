// write a program that uses pointers to set each element of an array to zero


// assuming it's an integer array... question didn't actually say
#include <stdio.h>
#include <stdlib.h>

#define MAX_INTS 20     // assuming no greater than 20 ints 

void zeros(int * array, int count)  {
    for (int i = 0; i < count; ++i) {
        *(array + i) = 0;
    }   
}


int main(int argc, char **argv) {
    
    // this isn't really worth doing with malloc, but i wanted to practice
    // using the function - prob simpler just to define an array w/ set size
    int *test = (int*)malloc(sizeof(int) * (argc - 1)); 
    unsigned short length = argc - 1; 
    
    if (argc > 1)   {
        for (short i = 1; i < argc; ++i)  {
            *(test + i - 1) = atoi(argv[i]);
        }
    } else {
        int test2[] = {1, 5, 2, 0, 5}; 
        length = sizeof(test2) / sizeof(int);
        
        test = realloc(test, sizeof(test2));
        for (short i = 0; i < length; ++i)  {
            test[i] = test2[i];    
        }

    }


    printf("before function, the array is:\t{");
    for (short i = 0; i < length; ++i)  {
        printf("% d", *(test + i));
    }
    printf(" }\n");    

    zeros(test, length);

    
    printf("after function, the array is:\t{");
    for (short i = 0; i < length; ++i)  {
        printf("% d", *(test + i));
    }
    printf(" }\n");    

    free(test);
    
    return(0);
}
