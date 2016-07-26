#include "../googletest/googletest/include/gtest/gtest.h"
#include "../Trader.h"

class TraderTest : public ::testing::Test
{
    public:
        Trader trader = Trader("Bob");
        Company company = Company("Apple", "APPL", 97.34);
        Company company2 = Company("Alphabet", "GOOG", 736.56);
        const long double originalNetWorth;
        const long double originalCapital;

        TraderTest():
            originalNetWorth(trader.netWorth()),
            originalCapital(trader.getCapital())
        {}
};


TEST_F (TraderTest, BuyStock) {
    // Have him buy some stock
    int32_t quantity = 9;
    auto stock = trader.buy(company, quantity);
    long double stockValue = company.getPrice() * quantity;

    // Check that his net worth remains the same
    ASSERT_EQ(originalNetWorth, trader.netWorth());

    // Check that his capital has decreased the correct amount
    long double expectedCapital = originalCapital - stockValue;
    ASSERT_EQ(expectedCapital, trader.getCapital());

    // Check that the trader owns the stock he purchased
}

TEST_F (TraderTest, SellStock) {
    // Have him buy some stock
    int32_t quantity = 10;
    auto stock = trader.buy(company, quantity);
    long double stockValue = company.getPrice() * quantity;

    // Check that his capital has decreased the correct amount
    long double expectedCapital = originalCapital - stockValue;
    ASSERT_EQ(expectedCapital, trader.getCapital());

    // Sell the stock
    trader.sell(company, quantity);

    // Check that his capital is at the original level
    ASSERT_EQ(originalCapital, trader.getCapital());
}

TEST_F (TraderTest, OwnStock) {
    // Have him buy some stock
    int32_t quantity = 40;
    auto stock = trader.buy(company, quantity);
    long double stockValue = company.getPrice() * quantity;

    // Check he owns the stock he just brought
    ASSERT_TRUE(trader.owns(company));

    // Check that he does not own stock that he hasn't brought
    ASSERT_FALSE(trader.owns(company2));
}