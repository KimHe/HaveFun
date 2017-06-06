#include "defs.h"

// subroutine for generating performance index JD
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
