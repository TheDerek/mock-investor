# mock-investor
Small sample program allowing for people to make mock investments in various real world companies.

## Example use of the API

**Source**

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

**Output**

    Bobs Capital: 9026.6
    Bobs net worth: 10000
    
    Apple increases by $10/share
    
    Bobs Capital: 9026.6
    Bobs net worth: 10100
