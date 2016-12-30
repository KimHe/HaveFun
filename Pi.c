// Program to compute Pi using Monte Carlo

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <omp.h>

double step;
float pi;
long int nIter=1000000000;

main(int argc, char* argv)
{
    int i;
    double x;
    long double sum =0.0;

    step = 1.0 / (double) nIter;

#pragma omp parallel for private (x) reduction(+:sum)
    for ( i=0; i<nIter; i++ ) {
        x = (i+0.5) * step;
        sum = sum + 4.0/(1.0 + x*x);
    } 
    pi = step * sum;
    printf("estimate of Pi is %f \n", pi);

}

