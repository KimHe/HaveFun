#include "defs.h"
#include <stdio.h>

struct string printStr(struct date today, double star_index[], struct date psy_date, struct date emo_date, struct date int_date)
{
    struct string s;

    // print out the simulation results
    printf("============================================== \n");
    printf("\t \t%d-%d-%d \n", today.year, today.month, today.day);
    printf("---------------------------------------------- \n");
    printf("\tToday is the %dth day of %d \n", dayNum(today), today.year);
    printf("============================================== \n");
    printf("  Physiologic index today: \t %.2f \n", *star_index);
    printf("  Psychologic index today: \t %.2f \n", *star_index+1);
    printf("  Intelligent index today: \t %.2f \n", *star_index+2);
    printf("  Next physiologic index: \t %d-%d-%d \n", psy_date.year, psy_date.month, psy_date.day);
    printf("  Next psychologic index: \t %d-%d-%d \n", emo_date.year, emo_date.month, emo_date.day);
    printf("  Next intelligent index: \t %d-%d-%d \n", int_date.year, int_date.month, int_date.day);
    printf("============================================== \n");

    //GTK PART: print the results    
    sprintf(s.str_date, "%d-%d-%d \n", today.year, today.month, today.day);
    sprintf(s.str_dayNum, "Today is the %dth day of year %d \n", dayNum(today), today.year);
    sprintf(s.str_psy, "%.2f", *star_index);
    sprintf(s.str_emo, "%.2f", *star_index+1);
    sprintf(s.str_int, "%.2f", *star_index+2);
    sprintf(s.str_Npsy, "%d-%d-%d", psy_date.year, psy_date.month, psy_date.day);
    sprintf(s.str_Nemo, "%d-%d-%d", emo_date.year, emo_date.month, emo_date.day);
    sprintf(s.str_Nint, "%d-%d-%d", int_date.year, int_date.month, int_date.day);

    return s;
}
