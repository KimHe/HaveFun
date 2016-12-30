// Program to compute Pi using Monte Carlo

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <omp.h>

#define SEED 35791246

int sampleInside(const int nSamples)
{
    int i, count=0;
    double x,y;

    srand(SEED);
    for (i=0; i<nSamples; i++){
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;
        if (x*x + y*y<=1) count++;
    }

    return count;
}

main(int argc, char* argv)
{
    long int nIter=50000000;
    int i, counter=0;
    float pi;

//    #pragma omp parallel for shared(nIter) reduction(+:counter)
    for (i=0; i<2; i++){
        counter += sampleInside(nIter);
    }

    pi = (double)counter/nIter * 2;
    printf("estimate of Pi is %g \n", pi);

}

