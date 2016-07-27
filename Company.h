//
// Created by derek on 25/07/16.
//

#ifndef MOCK_INVESTOR_COMPANY_H
#define MOCK_INVESTOR_COMPANY_H

#include <string>

class Company
{
    private:
        const long double ask;
        const long double bid;
        long double price;
        

    public:
        const std::string name;
        const std::string symbol;

        Company(std::string name, std::string symbol, long double price,
        long double ask, long double bid):
            name(name), symbol(symbol), price(price), ask(ask), bid(bid) {}

        Company(std::string name, std::string symbol, long double price):
            name(name), symbol(symbol), price(price), ask(price), bid(price) {}

        /** Get the last traded price of the stock. */
        long double getPrice() const;

        /** Get the ask price of the stock. */
        long double getAsk() const;

        /** Get the bid price of the stock. */
        long double getBid() const;

        void setPrice(long double price);

        /** Get a company from its stock symbol. */
        static Company get(std::string symbol);
};


#endif //MOCK_INVESTOR_COMPANY_H
