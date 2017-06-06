#include <stdio.h>
#include <math.h>
#include "defs.h"

int BIRTH[3] = {1988, 8, 11};

int main(int argc, char *argv[])
{
    int j;
    int next_index[3];
    int periodic[] = {23, 28, 33};
    int atol();

    double span;
    double star_index[3];

    struct date today, birth;
    struct date psy_date, emo_date, int_date;
    struct string s;


    // get the current time here
    today = getTime();

    // check the nargin
    if (argc == 1) {
        // put your birthday information here
        birth.year   = BIRTH[0];
        birth.month  = BIRTH[1];
        birth.day    = BIRTH[2]; 
    } else if (argc == 4) {
        birth.year   = atol(argv[1]);
        birth.month  = atol(argv[2]);
        birth.day    = atol(argv[3]); 
    } else {
        printf("Error: Please input your birthday in this format: yyyy m d (1988 8 11) \n");
        return 0;
    }

    // compute the today's index with respect to psycology, emotion, and intellegence
    span = GRE2JULE(today) - GRE2JULE(birth);
    
    for (j = 0; j < 3 ; j++){
        star_index[j] = 5.00 * sin(TWOPI * span / periodic[j]) + 5.00;
        next_index[j] = periodic[j] - ((int)span + periodic[j] * 3 / 4) % periodic[j] + (int)GRE2JULE(today) + 1;
    }

    // compute the date of next climax with respect to psy, emo, and int
    psy_date = JULE2GRE(next_index[0]);
    emo_date = JULE2GRE(next_index[1]);
    int_date = JULE2GRE(next_index[2]);

    // output the simulation results
    s = printStr(today, &star_index, psy_date, emo_date, int_date);

    // gui outputs
    gui(s);

    return 0;
}
