#include "compute-fib.hpp"
#include <stdint.h>

//Calculates Fibonacci to the x-th digit
uint64_t fibCalc(unsigned int x)
{
    if (x==0) return 0;
    if (x==1) return 1;
    
    return fibCalc(x-2) + fibCalc(x-1);
}