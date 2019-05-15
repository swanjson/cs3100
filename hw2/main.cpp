#include <iostream>
#include <string>
#include <iomanip>

#include "compute-fib.hpp"
#include "compute-e.hpp"
#include "compute-pi.hpp"

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