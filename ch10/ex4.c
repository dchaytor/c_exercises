/*  write a preprocessor macro that swaps two ints (extra challenge:  write
    one that does not use a temporary variable declared outside the macro   */

#define SWAP_INT(x, y) {int z = (y); (y) = (x); (x) = (z);}

#include <stdio.h>

int main(void)  {

    int x = 4, y = 3;

    printf("x: %d\t y: %d\n", x, y);
    SWAP_INT(x, y);
    printf("x: %d\t y: %d\n", x, y);


    return (0);
}
