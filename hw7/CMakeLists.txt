cmake_minimum_required(VERSION 3.0)
project(assign7)


set(CMAKE_CXX_FLAGS "-std=c++11 -pthread -O3 -g3 -Wall -Wextra${CMAKE_CXX_FLAGS}")

add_executable(assign7 
	main.cpp
)

