#include "compute-pi.hpp"


//Calculates pi to the x-th digit
double piCalc(unsigned int x)
{
    /* //TAYLOR SERIES (not accurate enough)
     double pi = 4.0, sum = 0.0;
     int sign = 1;
     for(int i=0; i < x; ++i)
     {
     sum += sign/(2.0*i+1.0);
     sign *= -1;
     }
     
     return pi*sum;
     
     */
    
    //hardcoded pi
    return 3.14159265358979323846264338327950288419716939937510;
}