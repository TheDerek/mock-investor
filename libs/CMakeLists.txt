# GTest
add_subdirectory(googletest/googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

SET(SOURCE_FILES ${SOURCE_FILES} fast-cpp-csv-parser/csv.h)