/*  write a procedure that counts the number of words in
    a string write a program to test your new procedure  */    

#include <stdio.h>

int wordCounter(const char *sentance) {
    /*  loop thru character array; when runs into series starting w/ 
        a non-space char, add to word. next time there's a space,
        resets checker valid                                         */

    char  newWordValid = 't';   // using this as logic var; init true
    short unsigned int nWords = 0;
    
    for(int i = 0; i < 500; ++i)    {
        char thisChar = sentance[i];
        
        if (thisChar == '\0') break;    // escape from loop if string over 
        
        if (thisChar == ' ')    {
            newWordValid = 't';   // next word could be new word; set true
        } else  {
            if (newWordValid == 't') ++nWords;
            newWordValid = 'f';
        }
 
    } // end for loop

    return nWords;    

}   // end wordCount


int main(void)  {
    while(1)    {
        char input[500];
        
        printf("enter a sentance to track the number of words (press \'q\' to quit):\n");

        fgets(input, sizeof(input), stdin);      

        if ((input[0] == 'q' || input[0] == 'Q') && input[1] == '\n')   break;  // break while loop if quit


        short unsigned int word_count = wordCounter(input);
        
        //printf("The sentance \"%s\" has %hu words\n", input, word_count);
        printf("this sentance has %hu words\n", word_count);
    }   // end while loop
}   // end main




