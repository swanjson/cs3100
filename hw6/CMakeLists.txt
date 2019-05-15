cmake_minimum_required(VERSION 3.0)
project(ComputePi)


set(CMAKE_CXX_FLAGS "-std=c++11 -pthread -O0 -g3 -Wall -Wextra${CMAKE_CXX_FLAGS}")

add_executable(ComputePi 
	main.cpp
	computePi.cpp
	computePi.hpp
	tableIt.cpp
	tableIt.hpp
	threadComputeSend.cpp
	threadComputeSend.hpp
)

