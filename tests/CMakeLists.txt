# Add test cpp file
set(TEST_FILES TraderTest.cpp CompanyTest.cpp PromptsTest.cpp DatabaseTest.cpp)
add_executable( runUnitTests ${TEST_FILES} )
target_link_libraries(runUnitTests gtest gtest_main mockLib curl sql sqlite3)
add_test( runUnitTests runUnitTests )