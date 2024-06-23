/*  write a program that counts the number of bits set in an integer. */

#include <stdio.h>

int numBitsSet(int number)  {

    int nBits = 0;
    const int BIT_MAX = 1 << 30; // not 31 to avoid sign bit
    for (int bit = 1; bit < BIT_MAX; bit = (bit << 1))   {
        nBits += ((bit & number) != 0);
    } // end for loop
    

    return nBits;
}


int main(void)  {
    
    printf("bits set in 5: %d\n", numBitsSet(5));
    printf("bits set in 1: %d\n", numBitsSet(1));
    printf("bits set in 32: %d\n", numBitsSet(32));
    printf("bits set in 900017: %d\n", numBitsSet(900017));

    return 0;
}
