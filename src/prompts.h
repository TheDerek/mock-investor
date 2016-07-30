//
// Created by derek on 30/07/16.
//

#ifndef MOCK_INVESTOR_PROMPTS_H
#define MOCK_INVESTOR_PROMPTS_H

#include <iostream>
#include "Trader.h"

Trader createTrader(std::ostream& = std::cout, std::istream& = std::cin);
Trader getTrader(std::ostream& = std::cout, std::istream& = std::cin);
std::string promptString(std::string, std::ostream&, std::istream&);
int32_t promptInt(std::string, std::ostream&, std::istream&);
bool promptBool(std::string, std::ostream &os = std::cout, std::istream &is = std::cin);

class NoUserFound : public std::exception {};

#endif //MOCK_INVESTOR_PROMPTS_H
