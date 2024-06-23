/* "write a program to take in a series of numbers & count the number
   of positive and negative values  */

#include <stdio.h>

int main()  {
    
    int num_in, num_pos = 0, num_neg = 0;

    puts("Enter a series of numbers, or press 0 to exit:");
    
    do {
        scanf("%d", &num_in);
        
        if (num_in > 0) ++num_pos;
        else if (num_in < 0) ++num_neg;
    } while (num_in != 0);

    printf("there were %d positive numbers and %d negative numbers entered\n", num_pos, num_neg);

    return (0);
}
