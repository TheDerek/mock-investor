//
// Created by derek on 25/07/16.
//

#ifndef MOCK_INVESTOR_COMPANY_H
#define MOCK_INVESTOR_COMPANY_H

#include <string>

class Company
{
    private:
        long double price;

    public:
        const std::string name;
        const std::string symbol;
        Company(std::string name, std::string symbol, long double price):
            name(name), symbol(symbol), price(price) {}
        long double getPrice() const;
        long double setPrice(long double price);
};


#endif //MOCK_INVESTOR_COMPANY_H
