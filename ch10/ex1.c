/*  write a macro that returns TRUE if its parameter is divisible by 10
    and false otherwise     */

#include <stdio.h>
#include <stdbool.h>

#define DIV10(x) (((x) % 10) == 0 ? true : false)

int main(void)  {

    bool temp = DIV10(10);

    printf("%d\n", temp); 

    return (0);
}
