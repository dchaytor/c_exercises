// write a program that reads a char and prints out whether it is a vowel or constonant

#include <stdio.h>


int main()  {
    char letter;    


    // read in char here, too lazy rn
    printf("enter a character to see if it's a vowel or not: ");
    scanf("%c", &letter);



    switch (letter) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            printf("the character %c is a vowel\n", letter);
            break;
        case 'y':
        case 'Y':
            printf("the character %c is sometimes a vowel\n", letter);
            break;
        default:
            printf("the character %c is not a vowel\n", letter);
            break; 
    }


    return (0);
}
