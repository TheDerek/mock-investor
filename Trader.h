//
// Created by derek on 25/07/16.
//

#ifndef MOCK_INVESTOR_TRADER_H
#define MOCK_INVESTOR_TRADER_H

#include <vector>
#include <string>
#include <unordered_map>

#include "Stock.h"

class Trader
{
    private:
        long double capital;
        const std::string name;
        std::unordered_map<std::string, Stock*> stocks;

    public:
        Trader(std::string name, long double capital = 10000):
            name(name), capital(capital) {}
        ~Trader();

        Stock& buy(Company &company, int32_t quantity);
        long double netWorth() const;
        long double getCapital() const;

        class NotEnoughCapital: public std::exception {};
};


#endif //MOCK_INVESTOR_TRADER_H
