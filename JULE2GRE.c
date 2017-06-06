#include "defs.h"

// subroutine for predicting next climax date
struct date JULE2GRE(int input)
{
    int J, N, L1, Y1, L2, M1, L3;
    struct date temp;

    J = (int)(input + 0.500);
    N = 4 * (J + 68569) / 146097;
    L1 = J + 68569 - (N * 146097 + 3) / 4;
    Y1 = 4000 * (L1 + 1) / 1461001;
    L2 = L1 - 1461 * Y1 / 4 + 31;
    M1 = 80 * L2 / 2447;
    temp.day = L2 - 2447 * M1 / 80;
    L3 = M1 / 11;
    temp.month = M1 + 2 - 12 * L3;
    temp.year = 100 * (N - 49) + Y1 + L3;

    return temp;
}
