#include <iostream>

#include "Company.h"
#include "Trader.h"
#include "prompts.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    // Main config file location
    std::string configPath = "~/.config/mock-trader";

    // Boot up mock investor
    cout << "Welcome to mock investor!" << endl;

    std::ofstream outfile ("test.txt");

    outfile << "my text here!" << std::endl;

    outfile.close();

    return 0;
}