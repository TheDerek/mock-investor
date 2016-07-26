//
// Created by derek on 25/07/16.
//

#ifndef MOCK_INVESTOR_STOCK_H
#define MOCK_INVESTOR_STOCK_H

#include <iostream>
#include "Company.h"

class Stock
{
    public:
        const int32_t quantity;
        const Company &company;

        Stock(Company &company, int32_t quantity):
            company(company), quantity(quantity) {}

        const long double equity();
};


#endif //MOCK_INVESTOR_STOCK_H
