#include <stdio.h>
#include <string.h>

int main()	{
    float cTemp;

    printf("Enter the temperature in celsius: ");
    scanf("%f", &cTemp);
    
    float fTemp = cTemp * 9.0/5.0 + 32;

    printf("The temperature in fahrenheit is %.1f degrees\n", fTemp);

   	return (0);
}


