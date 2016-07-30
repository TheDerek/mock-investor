#include "../libs/googletest/googletest/include/gtest/gtest.h"
#include "../src/Trader.h"

class CompanyTest : public ::testing::Test
{

};


TEST_F (CompanyTest, GetRemote) {
    Company company = Company::get("AAPL");

    ASSERT_EQ("AAPL", company.symbol);
    ASSERT_EQ("Apple Inc.", company.name);
}