//
// Created by derek on 25/07/16.
//

#include <stdio.h>
#include <curl/curl.h>

#include "Company.h"

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
    // Setup curl variables
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    // Only run if curl loaded correctly
    if(curl)
    {
        // Set curl options
        curl_easy_setopt(curl, CURLOPT_URL, "https://download.finance.yahoo"
            ".com/d/quotes.csv?s=AAPL&f=nl1ab");

        // Perform the request, putting the HTTP status code in res
        res = curl_easy_perform(curl);

        // Throw error if resource didn't exist
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        // Cleanup
        curl_easy_cleanup(curl);
        delete curl;
    }
}

void Company::setPrice(long double price)
{
    this->price = price;
}
