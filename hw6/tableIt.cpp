#include <iostream>
#include <thread> //for use of thread library
#include <vector>
#include <memory> //shared_ptr
#include <mutex> //for mutex  //std::lock_guard is an object that owns a mutex in a scope of a block.
#include <unordered_map> //for table of FIFO
#include <queue>
#include <functional> // std:ref <- constructs an object of the appropriate ref type to hold a reference to element
#include "tableIt.hpp"
#include "threadComputeSend.hpp"
#include "computePi.hpp"


void tableIt(std::unordered_map<int,int> &piTable, unsigned int prog, unsigned int digitOfPi, std::mutex &mutex2){
	//lock the second mutex, so threads are sequential
    std::lock_guard<std::mutex> lock2(mutex2);
    
    //put the progress of the thread into the digit of pi
    piTable[prog] = digitOfPi;
}
