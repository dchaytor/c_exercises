// write a program to print out the multiplication table

#include <stdio.h>


int main(void)  {

    // assuming 1-10 multiplication table - maybe make it so that can pick what size but eh


    int tableSize = 10;
    
    for (int i = 0; i <= tableSize; ++i)    {
        // using the 0 indices to print out first row (showing input to table)
                

        for (int j = 0; j <= tableSize; ++j)    {
            if (i == 0 && j == 0) printf("b");
            else if (i == 0 && j != 0) printf("\t%d", j);
            else if (j == 0 && i != 0) printf("%d", i);
            else printf("\t%d", i * j);
            

        } // end col loop

        printf("\n");

    } // end row loop






    return (0);

}
