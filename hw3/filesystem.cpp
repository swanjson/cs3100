#include <iostream> //std lib i/o
#include <unistd.h> // for getcwd(), chdir(), access(), sync(), chmod() and dup2() system calls
#include <sys/stat.h> // for chmod() call
#include "filesystem.hpp"

extern bool quittingTime;

//getcwd() //takes working directory (character string) as arg1 and size of(size_t) working directory as arg2
void getcwdFunction(){
    while (!quittingTime){
        char wd[4096]; //create character string w/ size for the working directory (used a massive size)
        getcwd(wd, sizeof(wd)); //system call to c string and size)
    }
    quittingTime=false;
}


//chdir() //takes path name to change into as arg
void chdirFunction(){
    while (!quittingTime)
        chdir("/proc/self/exe"); //hardcoded path continually changed into //BEWARE!!: don't make your own program non-executable or non-readable
    quittingTime=false;
}


//access() //takes path name as arg1 and mode(permissions??) as arg2
void accessFunction(){
    while (!quittingTime)
        access("/proc/self/exe", 7055);
    quittingTime=false;
}


//sync() //"always successful" //causes all pending modifications to filesystem metadata and cached file data to be written to the underlying filesystems.
void syncFunction(){
    while (!quittingTime)
        sync();
    quittingTime=false;
}

//chmod() //The chmod() system call takes a filename as its 1st argument, and an integer of type mode_t which describes the permission bits that should be set.
void chmodFunction(){
    while (!quittingTime)
        chmod("/proc/self/exe", 7055);
    quittingTime=false;
}

//dup2()
/*  This system call takes two integers as parameters. An interesting experiment for you to undertake is to observe the difference between these two calls:
        dup2(1, 2);
        dup2(100, 200);
    You might compare and contrast what htop() tells you about these variations vs. the watcher() function and strace. Of these, the former call is the correct one and the latter is incorrect in our program.
 
 The dup2() [dup2(int oldfd, int newfd) system call creates a copy of the file descriptor oldfd, using the file descriptor number specified in newfd.  If the file descriptor newfd was previously open, it is silently closed before being reused.
 
 */
void dup2Function(){
    while (!quittingTime)
        dup2(1,2); //difference between???? Use diff integers?
    quittingTime=false;
}


