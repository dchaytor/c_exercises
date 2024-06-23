/*  ex2:  write a macro is_digit that returns TRUE if its argument is
    a decimal digit     */

/*  ex3: write a second macro is_hex that returns true if its arguement
    is a hex digit. the 2nd macro should reference the first */

#include <stdio.h>

#define is_digit(x) ('0' <= (x) && (x) <= '9')
#define is_hex(x) (is_digit(x) || \
    ( 'A' <= (x) && (x) <= 'F') || ('a' <= (x) && (x) <= 'f'))


int main(void)  {

    printf("is 5 a digit:\t%d\n", is_digit('5'));
    printf("is x a digit:\t%d\n", is_digit('x'));
    printf("is 0 a digit:\t%d\n", is_digit('0'));
    printf("is o a digit:\t%d\n", is_digit('o'));
    printf("is 5 a hex:\t%d\n", is_hex('5'));
    printf("is a a hex:\t%d\n", is_hex('a'));
    printf("is C a hex:\t%d\n", is_hex('C'));
    printf("is F a hex:\t%d\n", is_hex('F'));
    return (0);
}

