//
// Created by derek on 25/07/16.
//

#include <stdio.h>
#include <curl/curl.h>
#include <iostream>

#include "Company.h"
#include "HTTPDownloader.h"
#include "fast-cpp-csv-parser/csv.h"

long double Company::getPrice() const
{
    return this->price;
}

long double Company::getAsk() const
{
    return this->ask;
}

long double Company::getBid() const
{
    return this->bid;
}

Company Company::get(std::string symbol)
{
    std::string url = "http://download.finance.yahoo"
            ".com/d/quotes.csv?s=AAPL&f=nl1ab";

    std::string content = Company::downloader.download(url);
    std::cout << content << std::endl;

    return Company("asd", "asd", 1);
}

void Company::setPrice(long double price)
{
    this->price = price;
}

HTTPDownloader Company::downloader = HTTPDownloader();