#include "defs.h"

int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// subroutine for calculating the day of a year
int dayNum(struct date today)
{
    int i;
    int sum;
    int numDay;

    // calculate the day number in one year
    if ( (today.year % 4 == 0 && today.year % 100 != 0) || today.year % 400 == 0){
        months[1] = 29;
    }

    for (i = 0, sum = 0; i < today.month-1; i++){
        sum += months[i];
    }

    numDay = sum + today.day;
    
    return numDay;
}
