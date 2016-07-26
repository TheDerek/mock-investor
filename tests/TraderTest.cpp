#include "../googletest/googletest/include/gtest/gtest.h"
#include "../Trader.h"

TEST (TraderTest, BuyStock) {
    // Create our trader
    Trader trader("Bob");
    auto originalNetWorth = trader.netWorth();
    auto originalCapital = trader.getCapital();

    // Create our company
    Company company("Apple", "APPL", 97.34);

    // Have him buy some stock
    int32_t quantity = 10;
    auto stock = trader.buy(company, quantity);
    long double stockValue = company.getPrice() * quantity;

    // Check that his net worth remains the same
    ASSERT_EQ(originalNetWorth, trader.netWorth());

    // Check that his capital has decreased the correct amount
    long double expectedCapital = originalCapital - stockValue;
    ASSERT_EQ(expectedCapital, trader.getCapital());
}