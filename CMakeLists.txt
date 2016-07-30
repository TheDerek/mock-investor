cmake_minimum_required(VERSION 3.5)

# GTest
add_subdirectory(googletest/googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Main project
project(mock_investor)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp Trader.cpp Trader.h Stock.cpp Stock.h Company.cpp
        Company.h fast-cpp-csv-parser/csv.h HTTPDownloader.cpp HTTPDownloader.h
        prompts.cpp prompts.h)
add_executable(mock_investor ${SOURCE_FILES})
target_link_libraries(mock_investor curl gtest)
add_library(mockLib ${SOURCE_FILES})

# Add test cpp file
set(TEST_FILES tests/TraderTest.cpp tests/CompanyTest.cpp tests/PromptsTest.cpp)
add_executable( runUnitTests ${TEST_FILES} )
target_link_libraries(runUnitTests gtest gtest_main mockLib curl)
add_test( runUnitTests runUnitTests )