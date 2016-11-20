#include <stdio.h>
#include <math.h>
#include <time.h>

struct date {
    int year;
    int month;
    int day;
};

double const TWOPI = 6.2831853071795864;

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

struct date JULE2GRE(int input)
{

    int J, N, L1, Y1, L2, M1, D, L3, M, Y;
    struct date temp;

    J = (int)(input + 0.500);
    N = 4 * (J + 68569) / 146097;
    L1 = J + 68569 - (N * 146097 + 3) / 4;
    Y1 = 4000 * (L1 + 1) / 1461001;
    L2 = L1 - 1461 * Y1 / 4 + 31;
    M1 = 80 * L2 / 2447;
    D = L2 - 2447 * M1 / 80;
    L3 = M1 / 11;
    M = M1 + 2 - 12 * L3;
    Y = 100 * (N - 49) + Y1 + L3;

    temp.year = Y;
    temp.month = M;
    temp.day = D;

    return temp;

}



int main()
{

	time_t t = time(NULL);
    double span, star_index[3];
    struct date today;
    struct date birth;
    struct date psy_date;
    struct date emo_date;
    struct date int_date;
  	struct tm tm = *localtime(&t);

    int i, j, sum=0, numDay, spanInt, todayInt, next_index[3];
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

    spanInt = (int)span;
    todayInt = (int)GRE2JULE(today);

    next_index[0] = 23 - (spanInt + 23 * 3 / 4) % 23 + todayInt + 1;
    next_index[1] = 28 - (spanInt + 28 * 3 / 4) % 28 + todayInt + 1;
    next_index[2] = 33 - (spanInt + 33 * 3 / 4) % 33 + todayInt + 1;

    psy_date = JULE2GRE(next_index[0]);
    emo_date = JULE2GRE(next_index[1]);
    int_date = JULE2GRE(next_index[2]);

    printf("===============================================\n");
    printf("                Output \n");
    printf("              %d-%d-%d \n", today.year, today.month, today.day);
    printf("===============================================\n");
    printf("    Today is the %dth day of year %d \n", numDay, today.year);
    printf("-----------------------------------------------\n");
    printf(" Psycological climax index: %.2f   \n", star_index[0]);
    printf(" Emotional    climax index: %.2f   \n", star_index[1]);
    printf(" Intellectual climax index: %.2f   \n", star_index[2]);
    printf("-----------------------------------------------\n");
    printf(" Next psycological climax: %d-%d-%d \n", psy_date.year, psy_date.month, psy_date.day);
    printf(" Next psycological climax: %d-%d-%d \n", emo_date.year, emo_date.month, emo_date.day);
    printf(" Next psycological climax: %d-%d-%d \n", int_date.year, int_date.month, int_date.day);
    printf("===============================================\n");

    return 0;

}

