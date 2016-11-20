#include <stdio.h>
#include <time.h>

int main(){
    int months[12], i, sum = 0, numDay;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

//    printf("month %d \n", tm.tm_mon);
//    printf("day %d \n", tm.tm_mday);

    if ((tm.tm_year+1900) % 4 == 0) {
        int months[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    } 
    else {
        int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    }

    for (i = 0; i < tm.tm_mon; i++){
        sum += months[i];
    }

    numDay = sum + tm.tm_mday;
     
    printf("Today is the %dth day of year %d \n", numDay, tm.tm_year+1900);
//    printf( "%d \n", numDay );
 
    return 0;
}
