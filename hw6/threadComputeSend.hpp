#pragma once

#ifndef THREADCOMPUTESEND_HPP
#define THREADCOMPUTESEND_HPP


void threadComputeSend(unsigned int digitOfPi, unsigned int prog, std::queue<int> &queue, std::unordered_map<int,int> &piTable, std::mutex &mutex1, std::mutex &mutex2);

#endif
