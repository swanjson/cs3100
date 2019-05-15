#ifndef PROCESS_HPP
#define PROCESS_HPP
#include <stdint.h> //give std types

void killFunction(pid_t pid, int sig);
void clockFunction();
void nanoSleepFunction(long timeNs);
void forkFunction();

#endif
