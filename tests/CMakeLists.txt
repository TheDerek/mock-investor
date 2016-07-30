# Add test cpp file
set(TEST_FILES TraderTest.cpp CompanyTest.cpp PromptsTest.cpp)
add_executable( runUnitTests ${TEST_FILES} )
target_link_libraries(runUnitTests gtest gtest_main mockLib curl sqlite3)
add_test( runUnitTests runUnitTests )