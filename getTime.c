#include <time.h>
#include "defs.h"

struct date getTime()
{
    struct date today;

    // get the date struct, tm
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    today.day    = tm.tm_mday;
    today.month  = tm.tm_mon + 1;
    today.year   = tm.tm_year + 1900;

    return today;
}
