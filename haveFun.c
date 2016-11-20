#include <stdio.h>
#include <math.h>
#include <time.h>

struct date {
    int year;
    int month;
    int day;
};

double const TWOPI = 6.2831853071795864;

double GRE2JULE(struct date input);


int main()
{

	time_t t = time(NULL);
    double span, star_index[3];
    struct date today;
    struct date birth;
  	struct tm tm = *localtime(&t);

    int i, j, sum=0, numDay;
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  	today.day    = tm.tm_mday;
  	today.month  = tm.tm_mon + 1;
  	today.year   = tm.tm_year + 1900;
    birth.day    = 11;
    birth.month  = 8;
    birth.year   = 1988;

    if (today.year % 4 == 0){
        months[1] = 29;
    }

    for (i = 0; i < today.month-1; i++){
        sum += months[i];
    }

    numDay = sum + today.day;


    span = GRE2JULE(today) - GRE2JULE(birth);
    
    star_index[0] = 5.00 * sin(TWOPI * span / 23.00) + 5.00;
    star_index[1] = 5.00 * sin(TWOPI * span / 28.00) + 5.00;
    star_index[2] = 5.00 * sin(TWOPI * span / 33.00) + 5.00;

    printf("===============================================\n");
    printf("                Output \n");
    printf("===============================================\n");
    printf("            Data:%d-%d-%d \n", today.year, today.month, today.day);
    printf("    Today is the %dth day of year %d \n", numDay, today.year);
    printf("-----------------------------------------------\n");
    printf("Psycological climax index: %.2f   \n", star_index[0]);
    printf("Emotional    climax index: %.2f   \n", star_index[1]);
    printf("Intellectual climax index: %.2f   \n", star_index[2]);
    printf("-----------------------------------------------\n");
    printf("Next psycological climax: \n");
    printf("Next psycological climax: \n");
    printf("Next psycological climax: \n");
    printf("===============================================\n");

}


double GRE2JULE(struct date input)
{
    double JD;
    double temp[3];

    temp[0] = 1461 * (input.year + 4800 + (input.month - 14) / 12) /4;
    temp[1] = 367 * (input.month - 2 - ((input.month - 14) / 12) * 12) / 12;
    temp[2] = 3 * (input.year + 4900 + (input.month - 14) / 12) / 100 / 4;
    JD = input.day - 32075 + temp[0] + temp[1] - temp[2] - 0.500;

    return JD;
}
