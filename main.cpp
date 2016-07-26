#include <iostream>

#include "Company.h"
#include "Trader.h"

int main()
{
    // Create our trader
    Trader trader("Bob");

    // Create our company
    Company company("Apple", "APPL", 97.34);

    // Have him buy some stock
    trader.buy(company, 10);

    // Bobs current capital
    std::cout << "Bob's Capital: " << trader.getCapital() << std::endl;

    // Bobs current net worth
    std::cout << "Bob net worth: " << trader.netWorth() << std::endl;

    // Increase the value of APPL
    company.setPrice(company.getPrice() + 10);
    std::cout << "\nApple increases by $10/share\n" << std::endl;

    // Bobs current capital
    std::cout << "Bob's Capital: " << trader.getCapital() << std::endl;

    // Bobs current net worth
    std::cout << "Bob net worth: " << trader.netWorth() << std::endl;

    return 0;
}