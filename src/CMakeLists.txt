# Main project
project(mock_investor)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES ${SOURCE_FILES} main.cpp Trader.cpp Trader.h Stock.cpp Stock.h
        Company.cpp Company.h prompts.cpp prompts.h HTTPDownloader.cpp
        HTTPDownloader.h)
add_executable(mock_investor ${SOURCE_FILES})
target_link_libraries(mock_investor curl gtest)
add_library(mockLib ${SOURCE_FILES})