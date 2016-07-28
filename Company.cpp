//
// Created by derek on 25/07/16.
//

#include <sstream>

#include "Company.h"
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
    // Build the API call using user input
    std::string url = "http://download.finance.yahoo"
            ".com/d/quotes.csv?s=" + symbol + "&f=nl1ab";

    // Download the content
    std::string content = Company::downloader.download(url);

    // Setup CSV reader
    std::istringstream str(content);
    io::CSVReader<4, io::trim_chars<'"'>> reader("company.csv", str);
    reader.set_header("name", "last", "ask", "bid");

    // Read the CSV string we just downloaded
    std::string name;
    double long last, ask, bid;

    while(reader.read_row(name, last, ask, bid))
        return Company(symbol, name, last, ask, bid);

    throw Company::NoCompanyFound();
}

void Company::setPrice(long double price)
{
    this->price = price;
}

HTTPDownloader Company::downloader = HTTPDownloader();