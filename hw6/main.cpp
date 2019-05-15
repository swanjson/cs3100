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

/* QUESTIONS AND NOTES
 * HTOP shows full use of 4 cores while running
 * How do threads join together? I understand the process but does it ask lock? Okay it must lock for each individually?
 * How does it not shut down kernal? What is making that priority list??
*/

int main() {
    //variables
    const int THOUSAND = 1000;
    unsigned int prog, digitOfPi;
    
    //initialized thread-safe data structures
    std::queue<int> queue;
    std::unordered_map<int,int> piTable;
    std::mutex mutex1, mutex2;
    
    //loading queue with 1- 1000
    for(int i = 1; i <= THOUSAND; i++)
        queue.emplace(i);

    //initialize vector of threads, size = "# of cores"
    std::vector<std::shared_ptr<std::thread> > threads;
    for (std::uint16_t core = 0; core < std::thread::hardware_concurrency(); core++)
		//I have to use emplace for multiple args
        threads.emplace_back(std::make_shared<std::thread>(threadComputeSend, digitOfPi, prog, std::ref(queue), std::ref(piTable), std::ref(mutex1), std::ref(mutex2)));
   
    // Wait for all of these threads to complete, then compile NEEDS TO HAPPEN RIGHT AFTER CALL ABOVE!
    for (auto&& thread : threads)
        thread->join();
    
    //lines between and beginning of pi
    std::cout << std::endl << std::endl << "3.";
    
    //print out pi digits from unordered_map
    for(int i = 0; i < piTable.bucket_count(); i++){
        //taking the second column of the table and printing it
        for(auto it = piTable.begin(i); it != piTable.end(i); it++)
            std::cout << it->second;
    }
    std::cout << std::endl << std::endl;
    
    return 0;
}
