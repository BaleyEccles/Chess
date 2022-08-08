//
// Created by Skyla on 28/7/2022.
//

#include "network_request.h"

std::pair<std::string, unsigned int> network_request(std::string method, std::string url) {
    try {
        // you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
        http::Request request{url};

        // send a get request
        const auto response = request.send(method);
        const std::string response_text = {response.body.begin(), response.body.end()};

//        std::cout << response_text;
        return {response_text, response.status.code};

    } catch (const std::exception& e) {
        throw e;
    }
}

std::string Method::GET = "GET";
std::string Method::POST = "POST";
std::string Method::PUT = "PUT";
std::string Method::_DELETE = "DELETE";