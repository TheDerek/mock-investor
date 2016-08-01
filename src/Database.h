//
// Created by derek on 30/07/16.
//

#ifndef MOCK_INVESTOR_DATABASE_H
#define MOCK_INVESTOR_DATABASE_H

#include <list>

#include "Trader.h"

class Database
{
    private:

    public:
        Database(std::string);
        std::string execute(std::string query);

        void saveTrader(Trader&);
        Trader getTrader(size_t id);
        std::list<Trader> getTraders();

};


#endif //MOCK_INVESTOR_DATABASE_H
