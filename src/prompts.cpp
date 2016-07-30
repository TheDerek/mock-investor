//
// Created by derek on 30/07/16.
//

#include <fstream>
#include <string>
#include "prompts.h"

Trader createTrader(std::ostream &os, std::istream &is)
{
    // Get the traders name
    os << "Please enter the new traders name:\n> ";
    std::string name;
    //is.ignore();
    getline(is, name, '\n');

    // Get the traders starting capital
    os << "Please enter the new traders starting capital:\n> $";
    std::string strCapital;
    //is.ignore();
    getline(is, strCapital, '\n');

    // Create the trader, use the default capital if the user didn't specify
    Trader trader = strCapital.empty()
                    ? Trader(name)
                    : Trader(name, std::stod(strCapital));

    return trader;
}

bool promptBool(std::string text, std::ostream &os, std::istream &is)
{
    // Prompt the user for a y/n
    os << text << std::endl;
    os << "(Y/n): ";

    // Get the users response
    char response;
    is >> response;

    // Convert the response to a bool and return
    return tolower(response) == 'y';
}
