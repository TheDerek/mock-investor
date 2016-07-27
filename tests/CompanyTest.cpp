#include "../googletest/googletest/include/gtest/gtest.h"
#include "../Trader.h"

class CompanyTest : public ::testing::Test
{

};


TEST_F (CompanyTest, GetRemote) {
    Company company = Company::get("APPL");
}