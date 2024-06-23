/*  write a function begins(string1, string2) that returns true if 
    string1 begins string2. write a program to test this function   */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>



bool begins(const char *string1, const char *string2)   {
    // strlen doesn't include null char - don't need to reaccount for
    unsigned int len = strlen(string1);
    // check to make sure string1 is at least as long as string2
    if (strlen(string2) < len) return false;

    bool itBegins = true;  // assume str1 begins str2 by default

    for(int i = 0; i < len; ++i)    {
        // assuming case sensitive
        if (string1[i] != string2[i]) itBegins = false;

    } // end for loop

    return itBegins;

} // end begins function


int main(void)  {

    printf("%d\n", begins("hi", "highschool"));    // should print 1
    printf("%d\n", begins("helter skelter", "heliospan"));  // should print 0
    printf("%d\n", begins("fallout", "falling"));  // should print 0


}
