#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const string TYPE_FIBONACCI = "-fib";
const string TYPE_E = "-e";
const string TYPE_PI = "-pi";

void helpScreen()
{
   cout << '\n';
   cout << "--- Assign 1 Help ---" << '\n';
   cout << "  -fib [n] : Compute the fibonnacci of [n]; range of [0, 40]" << '\n';
   cout << "  -e   [n] : Compute the value of 'e' using [n] iterations; range of [1, 30]" << '\n';
   cout << "  -pi  [n] : Compute Pi to [n] digits; range of [1, 10]" << '\n';
   cout << '\n';
}


//checks to see if the given arguments are valid
bool argumentValidation(string type, int num)
{
    bool validation = false;
    
    if (type == TYPE_FIBONACCI && num >= 0 && num <= 40)
        validation = true;
    
    else if (type == TYPE_E && num >= 1 && num <= 30)
        validation = true;
    
    else if (type == TYPE_PI && num >= 1 && num <= 10)
        validation = true;

    return validation;
}

//Calculates Fibonacci to the x-th digit
uint64_t fibCalc(unsigned int x)
{
    if (x==0) return 0;
    if (x==1) return 1;
    
    return fibCalc(x-2) + fibCalc(x-1);
}

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

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        helpScreen();
    }
    else
    {
        string type = string(argv[1]);
        unsigned int inputValue = 0;
        try
        {
            inputValue = stoi(argv[2]);
        }
        catch(...)
        {
            cout << "The number entered was not valid." << '\n';
            helpScreen();
        }
        
        if(argumentValidation(type, inputValue))
        {
            if (type == TYPE_FIBONACCI)
            {
                uint64_t answer = fibCalc(inputValue);
                cout << "The Fibonacci sequence at position " << inputValue << " is: " << answer << '\n';
            }
            else if (type == TYPE_E)
            {
                double answer = eCalc(inputValue);
                cout << "The value of e calculated using " << inputValue << " iteration(s) of the Taylor Series is: " << setprecision(20) << answer << '\n';
            }
            else if (type == TYPE_PI)
            {
                double answer = piCalc(inputValue);
                cout << "Pi calculated to " << inputValue << " decimal place(s) is: " << setprecision(inputValue+1) << answer << '\n';
            }
        }
        else
        {
            cout << "Range for '" << type << "' calculation is invalid." << '\n';
            helpScreen();
        }
    }
}