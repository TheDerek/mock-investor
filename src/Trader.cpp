//
// Created by derek on 25/07/16.
//

#include "Trader.h"
#include "Stock.h"


long double Trader::netWorth() const
{
    // Add the traders current capital to their net worth
    long double worth = capital;

    // Add all of the stocks the trader owns to their net worth.
    for(auto stock : stocks)
    {
        worth += stock.second->equity();
    }

    return worth;
}

Stock& Trader::buy(Company &company, int32_t quantity)
{
    // Calculate the cost to buy the number of stocks
    long double cost = (long double) quantity * company.getAsk();

    // Throw an exception if the trader cannot afford the transaction
    if(cost > this->capital)
        throw NotEnoughCapital();

    // Subtract the transaction cost from the traders capital
    this->capital -= cost;

    // If the trader already owns some of the stock add that amount to the new
    // value. This works because this function replaces any existing stock the
    // trader owns.
    if(stocks.count(company.symbol))
        quantity += stocks[company.symbol]->quantity;

    // Generate the deed for the trader
    Stock *stock = new Stock(company, quantity);

    // Add it to the traders owned stocks
    stocks[company.symbol] = stock;

    // Return the generated stock
    return *stock;
}

Trader::~Trader()
{
    for(auto pair : stocks)
    {
        delete pair.second;
    }
}

long double Trader::getCapital() const
{
    return capital;
}

void Trader::sell(Company &company, int32_t quantity)
{
    // Trader must own stock in that company
    if(!owns(company))
        throw DoesNotOwnStock();

    auto stock = getStock(company);

    // Trader must own the same or more than the amount of stock in the
    // company for the quantity he is selling
    if(quantity > stock.quantity)
        throw DoesNotOwnEnoughStock();

    // Refund the equity into the traders account
    auto equity = stock.equity();
    this->capital += equity;

    // Remove the stock from the traders book
    stocks.erase(company.symbol);
}

bool Trader::owns(Company &company) const
{
    return stocks.count(company.symbol) == 1;
}

Stock& Trader::getStock(Company &company)
{
    if(!owns(company))
        throw DoesNotOwnStock();

    return *stocks[company.symbol];
}
