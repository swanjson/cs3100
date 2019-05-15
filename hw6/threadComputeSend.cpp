#include <iostream>
#include <thread> //for use of thread library
#include <vector>
#include <memory> //shared_ptr
#include <mutex> //for mutex  //std::lock_guard is an object that owns a mutex in a scope of a block.
#include <unordered_map> //for table of FIFO
#include <queue>
#include <functional> // std:ref <- constructs an object of the appropriate ref type to hold a reference to element
#include "computePi.hpp" //file containing pi computation
#include "tableIt.hpp"
#include "threadComputeSend.hpp"

void threadComputeSend(unsigned int digitOfPi, unsigned int prog, std::queue<int> &queue, std::unordered_map<int,int> &piTable, std::mutex &mutex1, std::mutex &mutex2){
    
    while(!queue.empty()){
		{ //must bracket as sequences must happen individually between threads
        std::lock_guard<std::mutex> lock1(mutex1);
        }
        
        prog = queue.front();
        queue.pop();
        digitOfPi = computePiDigit(prog); //actual calculation with queue progress number.
        std::cout << "."; //print progress ".
	std::cout.flush(); // FLUSH AS RECOMMENDED BY INSTRUCTIONS 3.1
        tableIt(piTable, prog, digitOfPi, mutex2);  //send Table, queue progress number, calculated digit of pi, and second created mutex to table placer
    }
}
