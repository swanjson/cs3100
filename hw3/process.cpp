#include <iostream> //std lib i/o
#include <time.h> //allows for nanosleep and clock functions
#include <sys/types.h> //for fork system call  and pid_t
#include <sys/wait.h> //for wait call in fork call
#include <signal.h> //for kill() system call
#include <unistd.h> //for fork system call and pid_t
#include "process.hpp" //header file for process
#include <cstdio> // for NULL

extern bool quittingTime; //makes quittingTime work from main

//kill() wtih signal 0 and kill() wtih signal SIGUSR2 Make sure I send correct signals
void killFunction(pid_t pid, int sig){
    while (!quittingTime)
       kill(pid,sig);  //use raise(int)???
    quittingTime=false;
}
//clock() //takes no params
void clockFunction(){
    while (!quittingTime)
        clock();
    quittingTime=false;
}

//nanosleep() with delay "x" ns
void nanoSleepFunction(long timeNs){
    struct timespec req = {0}; //The structure timespec is used to specify intervals of time with nanosecond precision
    req.tv_sec = 0; //amount of seconds
    req.tv_nsec = timeNs; //amount of nanoseconds passed from main
    while (!quittingTime){
        nanosleep(&req, (struct timespec *)NULL); //first arg is intervals and second arg is time remaining (in this case none or NULL)
    }
    quittingTime=false;
}

//fork()
    //wait(): enables a parent process to block until its child terminates; also communicates the disposition of a child process back to its parent
    //exit(): inform the OS that this process wants to be removed from the queue of running processes
void forkFunction(){
    pid_t childPid;
    while (!quittingTime){
        if(!(childPid=fork()))  //could be different based on fork pid?? //if ((pid=fork())==0)
            exit(0);
        else
            wait(0); //continually waiting since child and parent are not the same???
    }
    quittingTime=false;
}
