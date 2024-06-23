#include <stdio.h>

/*  "Given an amount of money (less than $1.00), compute 
the number of quarters, dimes, nickels, and pennies needed."   */

int main()  {

    float money = 0.00;    // init to 0 for conditional
    int qcount = 0, dcount = 0, ncount = 0, pcount = 0;

    do  {
        // get input from user, and make sure it's within bounds
        printf("Enter the amount of money (pos values less than $1.00), or enter 0 to exit:  ");
        scanf("%f", &money);  // assuming that this way of reading in restricts to 2 dp
        
        
        // checking to make sure 0 not entered (tolerance check since using floats)
        if (money - 0 < 0.01) break;
        
    }   while (money > 1 || money < 0);
    


    // finding number of quarters
    qcount = (int) (money / 0.25);
    money = ((int)(100*money) % 25) / 100.0;   // remaining money without quarters
     
    // similar steps for other currency denoms
    dcount = (int) (money / 0.10);
    money = ((int)(100*money) % 10) / 100.0;   // remaining money without dimes

    ncount = (int) (money / 0.05);
    money = ((int)(100*money) % 5) / 100.0;    // remaining money without nickels

    pcount = (int) (money * 100);    

    // outputting results to console
    printf("Number of quarters:  %d\n", qcount);
    printf("Number of dimes:     %d\n", dcount);
    printf("Number of nickels:   %d\n", ncount);
    printf("Number of pennies:   %d\n", pcount);

    return 0;
}
