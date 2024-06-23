/*  design a structure to store time and date. write a function to find the difference
    between 2 times in minutes.                                         2023-07-15      */

// STILL NEED TO TEST THIS - particularly need to test month function, kinda complex


#include <stdio.h>
#define HOUR_TO_MIN 60
#define DAY_TO_MIN (HOUR_TO_MIN * 24)
#define YEAR_TO_MIN (DAY_TO_MIN * 365.25) // not wholly accurate w/ how we keep time; too lazy to do properly
// month_to_min needs to be handled separately since less consistent


// assuming date stored as YYYYMMDD, time as HHMMSS (in military time)
// will throw an error if incorrect format stored (i.e., hour 50) - assuming handled elsewhere
struct timelog  {
    // on second thought just going to store HHMM instead of HHMMSS
    // using bitfields b/c in practice, would likely need to store a large # of times as part of a log
    unsigned int year   :14;    // up to 16383
    unsigned int month  :4;     // up to 15 
    unsigned int day    :5;     // up to 31
    // 32 - 14 - 4 - 5 = 11 bits remaining in this - not sure if i have to handle or if comp will handle
    
    unsigned int hour   :5;     // up to 31
    unsigned int min    :6;     // up to 63 
    //unsigned int sec    :7;     // up to 127 - prob don't need since program only mentions mins
}


struct timelog logTime(unsigned int date, unsigned int time) {
    // assumes date comes in as YYYYMMDD
    // there might be a faster way to do this with bitshifts, but seems like a PITA
    unsigned short year = date % 10000;
    unsigned short month = (date -= year) % 100; // might have to split date -= into separate lines
    unsigned short day = (date -= month);  

    // assuming time is stored as HHMM
    unsigned short hour = time % 100;
    unsigned short min = (time -= hour);

    // store extracted data in a new timelog
    struct timelog newLog {year, month, day, hour, min};

    return newLog; // returning timelog to user
}

// returns a date from datetime object as YYYYMMDD format
int _getYMD(stuct timelog tl)  {
    return (tl.day + tl.month * 100 + tl.year * 10000);
}


// assumes days themselves handled elsewhere; i.e., gets from day 0 of 2nd month to day 0 of 1st
// month2 is assumed the month of the greater date OVERALL; month1 is the month of the lesser date 
int monthToMin(int month2, int month1)  {
    int nDays = 0, cMonth, endMonth;
    short mp = 0;

    if (month2 >= month1); 
        cMonth = month1;
        endMonth = month2;
        mp = 1;     // assumed case is that month2 is greater than month1
    } else    {
        cMonth = month2;
        endMonth = month1;
        mp = -1;    
    }

    while (cMonth != endMonth)    {
        if (cMonth >= 13) cMonth = 1; // shouldn't need this, but just in case yknow
        
        switch (cMonth) {
            case 2: // february - 28 days (handling extra day as part of years)
                nDays += mp * 28;
                break;
            case 4: // handling all the months w/ 30 days (using fallthroughs)
            case 6:
            case 9:
            case 11:
                nDays += mp * 30;
                break;
            default;    // handles all months with 31 days
                nDays += mp * 31;
                break;

        }

        ++cMonth;
    }    

 
    return nDays * DAY_TO_MIN; 
}


int timeDifferenceMins(struct timelog dateTime1, struct timelog dateTime2)  {
    int difference = 0;
    
    // assume date2 < date1 for calculating difference in time; will account for later
    difference += (dateTime2.min - dateTime1.min);
    difference += (dateTime2.hour - dateTime1.hour) * HOUR_TO_MIN; 

      
    // this'd be way easier if it was in YYYYMMDD format lmao, could just be 1 comparison
    /* if stupid workaround doesn't work uncomment this and finish
    if (dateTime1.year > dateTime2.year)    {

    } else if (dateTime1.year < dateTime2.year) {

    } else    {
        // this is the case where years are equal - need to check month/date
    }
    */

    // check if dateTime1 is after dateTime2 (assumption); handle case where it isn't
    int delYMD = _getYMD(dateTime2) - _getYMD(dateTime1);
    if (delYMD > 0) {
        // assumtion case; handle as expected
        difference += (dateTime2.year - dateTime1.year) * YEAR_TO_MIN;        
        difference += monthToMin(dateTime2.month, dateTime1.month);
        difference += (dateTime2.day - dateTime1.day) * DAY_TO_MIN;

    } else if (delYMD < 0)  {
        /*  opposite of assumption case: second date was later than the first. flip whatever 
            the current value of difference is, then add date diff considering 2nd date as 
            number being subtracted from        */
        difference = 0 - difference; // could do *= -1 or -difference  but afaik addition is faster
        difference -= (dateTime2.year - dateTime1.year) * YEAR_TO_MIN;        
        difference -= monthToMin(dateTime2.month, dateTime1.month); // might have to change to += and swap order or dates
        difference -= (dateTime2.day - dateTime1.day) * DAY_TO_MIN;

    } // note: case where delYMD == 0 doesn't need checking since by def there is no difference


    // not sure if question wants difference to be signed, or just as absolute difference between dates
    // going to stick with signed for now, as in should output the minutes to go from date1 TO date2
    return difference;
}


int main(void)  {
    
//    printf("The difference between 

    // still need to test this lol

    return (0);
}

