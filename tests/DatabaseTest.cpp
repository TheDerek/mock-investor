#include "../libs/googletest/googletest/include/gtest/gtest.h"
#include "../src/prompts.h"
#include "../src/Database.h"

#include <istream>
#include <ostream>

class DatabaseTest : public ::testing::Test {};


TEST_F (DatabaseTest, createDatabase) {
    Database db("test.db");
}