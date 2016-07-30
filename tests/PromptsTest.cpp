#include "../googletest/googletest/include/gtest/gtest.h"
#include "../prompts.h"

#include <istream>
#include <ostream>

class PromptsTest : public ::testing::Test {};


TEST_F (PromptsTest, createTrader) {
    std::istringstream input("Joe\n30000\n");
    Trader trader = createTrader(std::cout, input);
    ASSERT_EQ("Joe", trader.name);
    ASSERT_EQ(30000, trader.getCapital());
    std::cout << "\nName : " << trader.name << ", capital: " << trader
        .getCapital() << std::endl;
}