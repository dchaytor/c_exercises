/*  write a function that takes a single string as its argument and
    returns a pointer to the first nonwhite character in the string */

#include <stdio.h>

char *firstNWChar(char * stringIn)   {
	while (*stringIn != '\0')	{
		if (*stringIn != ' ')	 break;		// break loop if non-whitespace
    	stringIn++;
	}
	
	return stringIn;	// returns either end of string char or first non-empty char
}


/* 	i *would* do input argument from command line, but i don't think that would work for this
	with how whitespace is handled on cml... and ngl i hate taking arbitrary user input from
	prompts so i'm just not going to bother!   */
int main(void)  {
    char test[] = "   Asfljasl lksjdflk ";	// default test case
	//char test[] = "                    ";		// testing case of empty string
    //char test[] = "asf";						// testing trivial case
	
	char *p = firstNWChar(test);
	if (*p == '\0')	printf("String is entirely whitespace\n");
	else printf("The first character of the string <<%s>> is <<%c>>\n", test, *p);

    return(0);  
}
