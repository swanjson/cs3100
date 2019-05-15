#include <iostream>
#include <array> // for 2D array and
#include <deque> // for FIFO Data Structure

void printAnomReport(int anomCount, unsigned int &seqNum, unsigned int &frameSize, int &oldPageFaults, int &newPageFaults)
{
    std::cout << "Anomaly Discovered!" << std::endl;
    std::cout << "\t Sequence: " << seqNum + 1 << std::endl;
    std::cout << "\t Page Faults: " << oldPageFaults << " @ Frame Size: " << frameSize - 1 << std::endl;
        std::cout << "\t Page Faults: " << newPageFaults << " @ Frame Size: " << frameSize << std::endl << std::endl;
    anomCount++;
}

int main(){
    
    const int THOU = 1000, HUND = 100;
    std::array<std::array<int,1000>, 100> resArr; //array of 100 arrays of size 1000
    std::srand((unsigned)time(NULL)); //seeding random
    int oldPageFaults, pos, x;
    unsigned int current = 0;
    int newPageFaults = 0, anomCount = 0;
    std::deque<int> pageRepl;
    std::array<bool,250> table;
    
    //Print Initial Report
    std::cout << std::endl << std::endl;
    std::cout << "Number of sequences tested: " << THOU << std::endl;
    std::cout << "Length of memory reference string: " << HUND << std::endl << std::endl;

    
    //initializing 100 different 2D arrays of 1000 random numbers ranging from 1-250
    for(int i=0; i < 100; i++)
        for (int j=0; j < 1000; j++)
            resArr[i][j] = (std::rand()%250)+1;
    
    //looping through # of sequences (100)
    for(unsigned int seqNum=0; seqNum < 100; ++seqNum){
        //looping through # of arrays (100) of size 1000
        for(unsigned int i=0; i < 100; ++i){
            while(current < resArr[seqNum].size()){
                x = resArr[seqNum][current];
                if (table[x] == 0){
                    if (pageRepl.size() >= i+1){
                        pos = pageRepl.front();
                        table[pos] = 0;
                        pageRepl.pop_front();
                    }
                    table[x] = 1;
                    pageRepl.emplace_back(x);
                    newPageFaults++;
                }
                current++;
            }
            //MIGHT NEED TO REMOVE seqNum ARG.
            if(oldPageFaults != 0 and newPageFaults > oldPageFaults /*ADD FIRST CASE HERE?*/)
                printAnomReport(anomCount, seqNum, i, oldPageFaults, newPageFaults);
            oldPageFaults = newPageFaults;
            newPageFaults = 0;
            for(int i = 0; i < 250; i++)
                table[i] = false;
            pageRepl.clear();
            current = 0;
        }
        oldPageFaults = 0;
    }
    return 0;
}



/* QUESTIONS AND TODO:
 
 -Get rid of print function? maybe be causing issues through passing?
 -First sequence always showing up...??
 -Unsigned vs signed causing errors???
 
 
 
 
 */
