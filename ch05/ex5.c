#include <stdio.h>
#include <string.h>

int main()  {
    unsigned int hours, mins;    

    printf("Enter the time elapsed [h min]: ");
    scanf("%u %u", &hours, &mins);

    unsigned long int t_mins = hours * 60 + mins;
    
    printf("The time in minutes is %lu minutes\n", t_mins); 

    return 0;

}
