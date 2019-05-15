#include <iostream>
#include <cstdlib>
#include <unistd.h> //for pid_t and getpid
#include <sys/types.h> //for pid_t and getpid
#include <csignal> //std library to recognize SIGINT and SIGUSR2?
#include <cstdio> // for NULL
#include <sys/wait.h>
#include <signal.h> //library to recognize SIGINT and SIGUSR2

//include the header files which link to the cpp DO NOT INCLUDE CPP FILES!
#include "c++lang.hpp"
#include "filesystem.hpp"
#include "process.hpp"

#define VERSION "1.4"

/* QUESTIONS
 -CHECK MY KILL SYSTEM CALL AND SEE IF IT IS SENDING SIGNALS TO SELF. Sould I be using "raise()"?
 -Why don't SIGINT and SIGUSR2 have to be defined? Included/defined/given in signal.h??
 -CPU/IO Bound per processor?
 -Am I going to have to add arguments???
 -wtf is "/proc/self/exe"?? "it will always refer to your own program, no matter where that file exists on the system." but I can mess up permission bits by adding wrong param???
 -My fork() is prolly messed up. How do I use wait() and exit() functions? Parent/Child values??
 -0755 or 7055 is default permissions???
 -What integers should I be using for dup2? Is dup2 for canceling out stdin/out and for making more pipes possible??
 -What library is the new operator in?
*/

bool quittingTime = false;
int zeroSignal = 0;

void nullCtrlC(int a){
    quittingTime = true;
}
//what is the diff between "char** argv" and "char* argv[]"? check on this.
int main(int argc, char** argv){
    //prints PID when programs starts up
    pid_t pidStart = getpid(); //sets a variable "pid" to the Process ID value
    printf("\nPID of program upon start:%d \n", pidStart);
    while (!quittingTime){
        
        signal(SIGINT, nullCtrlC); //(which signal I wish to change, with which function should run)
        
        pid_t pid = getpid(); //sets a variable "pid" to the Process ID value
        
        char resp;
        //main menu
        printf("\nTime wasting main menu (v" VERSION ") PID:%d \n"
        "\t0) addition operator \n"
        "\t1) function from cmath()\n"
        "\t2) new/delete\n"
        "\t3) just new operator\n"
        "\t4) kill() wtih signal 0\n"
        "\t5) kill() wtih signal SIGUSR2\n"
        "\t6) clock()\n"
        "\t7) nanosleep() with a delay of 1ns\n"
        "\t8) nanosleep() with a delay of 1,000ns\n"
        "\t9) nanosleep() with a delay of 1,000,000ns\n"
        "\ta) nanosleep() with a delay of 1,000,000,000ns\n"
        "\tb) fork()  with exit() and wait()\n"
        "\tc) getcwd()\n"
        "\td) chdir()\n"
        "\te) access()\n"
        "\tf) sync()\n"
        "\tg) chmod()\n"
        "\th) dup2()\n"
        "\tq) Quit program\n"
        "> ", pid);
        
        std::cin >> resp;
        
        
        
        //switch statement for main menu options
        switch (resp){
        case '0':
		std::cout<< "Running an arithmetic operator...\n";
                arithmetic(); //uses repetative addition
            break;
            
        case '1':
	    	std::cout<<"Running a cmath function...\n";
                cmathFunction(); //uses square root [sqrt()]
            break;
            
        case '2':
               	std::cout<<"Running new operator w/ delete...\n";
                newDeleteFunction(); //dynamically creates and deletes char[8192]
            break;
            
        case '3':
               	std::cout<<"Running new operator w/o delete...\n";
                justNewFunction(); //dynamically creates char[8192] w/o deleting
            break;
            
        case '4':
                std::cout<<"Running kill() with signal 0...\n";
                killFunction(pid, zeroSignal); //sends PID and zero
            break;
            
        case '5':
                std::cout<<"Running kill() with signal SIGUSR2...\n";
                killFunction(pid, SIGUSR2); //sends PID and SIGUSR2
            break;
            
        case '6':
                std::cout<<"Running clock()...\n";
                clockFunction(); //continually runs the clock function
            break;
            
        case '7':
                std::cout<<"Running nanosleep() for 1 ns...\n";
                nanoSleepFunction(1);
            break;
            
        case '8':
               std::cout<<"Running nanosleep() for 1,000 ns...\n";
                nanoSleepFunction(1000);
            break;
            
        case '9':
               std::cout<<"Running nanosleep() for 1,000,000 ns...\n";
                nanoSleepFunction(1000000);
            break;
            
        case 'a':
        case 'A':
                std::cout<<"Running nanosleep() for 1,000,000,000 ns...\n";
                nanoSleepFunction(1000000000);
            break;
            
        case 'b':
        case 'B':
                std::cout<<"Running fork()...\n";
                forkFunction();
            break;
            
        case 'c':
        case 'C':
                std::cout<<"Running getcwd()...\n";
                getcwdFunction();
            break;
            
        case 'd':
        case 'D':
                std::cout<<"Running chdir()...\n";
                chdirFunction();
            break;
            
        case 'e':
        case 'E':
                std::cout<<"Running access()...\n";
                accessFunction();
            break;
            
        case 'f':
        case 'F':
                std::cout<<"Running sync()...\n";
                syncFunction();
            break;
            
        case 'g':
        case 'G':
                std::cout<<"Running chmod()...\n";
                chmodFunction();
            break;
                
        case 'h':
        case 'H':
                std::cout<<"Running dup2()...\n";
                dup2Function();
            break;
            
        case 'q':
        case 'Q':
            quittingTime = true;
            break;
            
        default:
            std::cout<<"Please select one of the listed options. Again...\n";
            break;
        }
    }
return 0;
}
