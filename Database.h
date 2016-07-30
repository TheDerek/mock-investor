//
// Created by derek on 30/07/16.
//

#ifndef MOCK_INVESTOR_DATABASE_H
#define MOCK_INVESTOR_DATABASE_H


class Database
{
    public:
        static Database load(std::string path);
        static Database create(std::string path);

        void saveTrader(Trader&);
        Trader getTrader(size_t id);
        std::array<Trader> getTraders();

};


#endif //MOCK_INVESTOR_DATABASE_H
