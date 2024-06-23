/*  write a function count(number, array, length) that counts
    the number of times number appears in array. the array has
    length elements. the function should be recursive. write a
    test program to go with the function                        */


#include <stdio.h>

int count(int number, int array[], unsigned short length) {
    int rCount = 0;    // might have to add some kind of conditional, like if length == sizeof(array)
    
    --length;
     
    if (length > 0) {
        rCount += count(number, array, length);
        //printf("%d %d %d\n", number, array[length], rCount); 
        if (number == array[length]) ++rCount;
    } 

    return rCount;

}   //end count function



int main(void)  {

    int test [6] = {1, 2, 1, 1, 6, 1};

    printf("%d\n", count(1, test, sizeof(test)));



}
