/*  write a set of parameterized macros, "clear_bit" and "test_bit", to go
    with the "set_bit" operation defined in example 11-3. write a main 
    program to test these macros    */
#include <stdio.h>

#define X_SIZE 24
#define Y_SIZE 8

char graphics[X_SIZE / 8][Y_SIZE];
void print_graphics(void);

#define set_bit(x, y) graphics[(x)/8][y] |= (0x80 >> ((x) % 8))
#define clear_bit(x, y) graphics[(x)/8][y] &= ~(0x80 >> ((x) % 8))
#define test_bit(x, y) ((graphics[(x)/8][y] & (0x80 >> ((x) % 8)) ? 1 : 0)) 


int main(void)  {

    // going to start by setting all bits to 1
    for (short i = 0; i < X_SIZE; ++i) {
        for (short j = 0; j < Y_SIZE; ++j)    {
            set_bit(i, j);
        }
    }

    printf("printing fully set map:");
    print_graphics();    

    // clearing a bit at 20, 5
    clear_bit(20, 5);
    printf("printing map with bit cleared at 20, 5");  
    print_graphics();

    // testing bit at 20, 5, as well as some arbitrary bit
    printf("bit at (20, 5): %d\n", test_bit(20, 5)); 
    printf("bit at (10, 8): %d\n", test_bit(10, 8));


    return (0);
}   


void print_graphics(void)   {


    printf("\n");
    for (short y = 0; y < Y_SIZE; ++y)    {
        for (short x = 0; x < X_SIZE/8; ++x)    {
            for (unsigned int bit = 0x80; bit > 0; bit = (bit >> 1)) {
                if ((graphics[x][y] & bit) != 0) printf("X");
                else printf("."); 
            } // end bit loop
        } // end x loop
        printf("\n");
    } // end y loop
    printf("\n");
}
