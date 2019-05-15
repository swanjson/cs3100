#include "compute-e.hpp"
#include <stdint.h>

using namespace std;

uint64_t factorial(unsigned int x)
{
    if(x > 1)
        return x* factorial(x-1);
    else
        return 1;
}

//e calculated with taylor series
double eCalc(unsigned int x)
{
    double e = 0.0;
    
    for(int i = 0; i<x; ++i)
        e += 1.0/(factorial(i));
    
    return e;
}