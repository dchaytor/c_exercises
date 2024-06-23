/*  write a program that prints out an input number (from 1-100) the way 
    we say them e.g., 85 would be eighty five, 13 would be thirteen, etc.    */


#include <stdio.h>


int main(void)  {

    //char hund = n, tens = n, ones = n;     // this works for reading in 1 at a time but is also kinda ungabunga
    char teens = 'n';

    printf("enter a number to pronounce:\t");
    //scanf("%c%c%c", &hund, &tens, &ones); // this is retarded but i'm too lazy to fix 
    

    int num_in;
    scanf("%d", &num_in);    // fml`
    int ones = num_in % 10;
    int tens = (num_in / 10) % 10;
    int hunds = (num_in / 100) % 10;    

    // printf("%c, %c, %c", hund, tens, ones);
    

    printf("the number %d is pronounced", num_in);

    //going thru hundreds
    switch (hunds)   {
        case 1:
            printf(" one-hundred");
            break;
        default:    // says to only worry about numbers 1-100 and i'm lazy
            break;
    }

    switch (tens)   {
        case 1:
            teens = 'y';
        case 2:
            printf(" twenty");
            break;
        case 3:
            printf(" thirty");
            break;
        case 4:
            printf(" fourty");
            break;
        case 5:
            printf(" fifty");
            break;
        case 6:
            printf(" sixty");
            break;
        case 7:
            printf(" seventy");
            break;
        case 8:
            printf(" eighty");
            break;
        case 9:
            printf(" ninety");
            break;
    }

  
    switch (ones)   {
        case 0: 
            if (teens == 'y') printf(" ten");
            break;
        case 1:
            if (teens != 'y') printf(" one");
            else printf(" eleven");
            break;
        case 2:
            if (teens != 'y') printf(" two");
            else printf(" twelve");
            break;
        case 3:
            if (teens != 'y') printf(" three");
            else printf(" thirteen");
            break;
        case 4:
            if (teens != 'y') printf(" four");
            else printf(" fourteen");
            break;
        case 5:
            if (teens != 'y') printf(" five");
            else printf(" fifteen");
            break;
        case 6:
            if (teens != 'y') printf(" six");
            else printf(" sixteen");
            break;
        case 7:
            if (teens != 'y') printf(" seven");
            else printf(" seventeen");
            break;
        case 8:
            if (teens != 'y') printf(" eight");
            else printf(" eighteen");
            break;
        case 9:
            if (teens != 'y') printf(" nine");
            else printf(" ninteen");
            break;
    }

    printf("\n");     

    return (0);
}
