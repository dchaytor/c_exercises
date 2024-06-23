/*  Print a checker board (8-by-8 grid); each square
    should be 5-by-3 characters wide    */

#include <stdio.h>


int main(void)  {
    
    int w = 5;      // width of square
    int h = 3;      // height of square
    int gridsize [2] = {8, 8};   // grid size in rows, columns 
    char wFill = '-';
    char hFill = '|';

    // looping thru grid to print squares
    for (int i = 0; i < gridsize[0]; ++i)    {
    
        printf("+");

        // print first row
        for (int j = 0; j < gridsize[1]; ++j)   {

            for (int w_ct = 0; w_ct < w; ++w_ct)   printf("%c", wFill);
            printf("+");
            
        } // end col loop
        
        // print other rows

        for (int r_ct = 0; r_ct < h; ++r_ct)    {
                printf("\n");
                
            for (int j = 0; j < gridsize[1]; ++j)   {
                printf("%c", hFill);
                for (int w_ct = 0; w_ct < w; ++w_ct)    {
                    printf(" ");
                }
                

            }

            printf("%c", hFill);  // printing last | char            
        }            


        printf("\n");
    } // end row loop



    // print last  row
    for (int j = 0; j < gridsize[1]; ++j)   {

        printf("+");
        for (int w_ct = 0; w_ct < w; ++w_ct)   printf("%c", wFill);
        
    }

    printf("+\n");


    return(0);
}

