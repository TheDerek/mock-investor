//
// Created by derek on 28/07/16.
//

#ifndef MOCK_INVESTOR_HTTPDOWNLOADER_H
#define MOCK_INVESTOR_HTTPDOWNLOADER_H


/**
 * HTTPDownloader.hpp
 *
 * A simple C++ wrapper for the libcurl easy API.
 *
 * Written by Uli Köhler (techoverflow.net)
 * Published under CC0 1.0 Universal (public domain)
 */

#include <string>

/**
 * A non-threadsafe simple libcURL-easy based HTTP downloader
 */
class HTTPDownloader {
public:
    HTTPDownloader();
    ~HTTPDownloader();
    /**
     * Download a file using HTTP GET and store in in a std::string
     * @param url The URL to download
     * @return The download result
     */
    std::string download(const std::string& url);
private:
    void* curl;
};

#endif //MOCK_INVESTOR_HTTPDOWNLOADER_H