cmake_minimum_required(VERSION 3.8)
project(LRU)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LRU.h.h LRUTemplate.h)
add_executable(LRU ${SOURCE_FILES})