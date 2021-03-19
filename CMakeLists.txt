cmake_minimum_required(VERSION 3.17)
project(Jarvis)

set(CMAKE_CXX_STANDARD 14)

add_executable(Jarvis src/main.cpp src/storage/kvstore.cpp src/storage/kvstore.h)