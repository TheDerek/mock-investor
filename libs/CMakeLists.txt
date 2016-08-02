# GTest
add_subdirectory(googletest/googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# SQL stuff
FILE(GLOB sql_source_files sqlite3pp/src/*)
add_library(sql ${sql_source_files})


# CSV
include_directories(fast-cpp-csv-parser)

#SET(SOURCE_FILES ${SOURCE_FILES} fast-cpp-csv-parser/csv.h)