/*  write a function that takes a single string as its argument and
    returns a pointer to the first nonwhite character in the string */


#include <stdio.h>


char *firstNWChar(char * stringIn, int count)   {
    char *p = stringIn;

    for (short i = 0; i < count; ++i)   {
        if (*p != ' ') break;
        ++p;
    }

    return p;
}

// i'm too lazy to do input arguments on this one
int main(void)  {
    char test[] = "   Asfljasl lksjdflk ";

    char *p = firstNWChar(test, sizeof(test) / sizeof(char));
    
    printf("%c\n", *p);

    return(0);  
}
