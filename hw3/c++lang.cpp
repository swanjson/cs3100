#include <iostream> //std namespace i/o
#include <math.h> //functions like sqrt(), abs(), a tan() //cmath is for std namespace and math.h is for all
#include <vector> //to allocate memory with new operator for vectors??
#include <new> //for new operator??
#include "c++lang.hpp"

extern bool quittingTime; //makes quittingTime work from main

//arithmetic operation function
void arithmetic(){
    int sum = 0;
    while(!quittingTime){
        int sum = 1 + 1;
        sum = 0;
    }
    quittingTime = false;
}

//function from cmath library
void cmathFunction(){
    float num = 4;
    while(!quittingTime){
        sqrt(num);
        num = 4;
    }
    quittingTime = false;
}

// new/delete operators
void newDeleteFunction(){
    while(!quittingTime){
        char *newChar = new char[8192];
        delete[] newChar;
    }
    quittingTime = false;
}

//just new operator
void justNewFunction(){
    while(!quittingTime)
        char *newChar = new char[8192];
    quittingTime = false;
}


