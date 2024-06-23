/*  write a program to draw a 10x10 bitmapped square    */

#include <stdio.h>
   
#define X_SIZE 16
#define Y_SIZE 16

char graphics[X_SIZE / 8][Y_SIZE];
void print_graphics(void);

#define set_bit(x, y) graphics[(x)/8][y] |= (0x80 >> ((x) % 8))
#define clear_bit(x, y) graphics[(x)/8][y] &= ~(0x80 >> ((x) % 8))
#define test_bit(x, y) ((graphics[(x)/8][y] & (0x80 >> ((x) % 8)) ? 1 : 0)) 

#define draw_box(x_start, y_start, sizex, sizey) do {   \
    for (int x = x_start; x < x_start + sizex; ++x) {   \
        set_bit(x, y_start);                            \
        set_bit(x, y_start + sizey - 1);   }            \
    for (int y = y_start; y < y_start + sizey; ++y) {   \
        set_bit(x_start, y);                            \
        set_bit(x_start + sizex - 1, y);   }            \
    } while(0)                                          \


int main(void)  {

    // start by setting all bits to 0
    for (short i = 0; i < X_SIZE; ++i) {
        for (short j = 0; j < Y_SIZE; ++j)    {
            clear_bit(i, j);
        }
    }

    draw_box(1, 5, 7, 3);
    print_graphics();


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
