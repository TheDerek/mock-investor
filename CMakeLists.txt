cmake_minimum_required(VERSION 3.5)
project(mock_investor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Trader.cpp Trader.h Stock.cpp Stock.h Company.cpp Company.h)
add_executable(mock_investor ${SOURCE_FILES})