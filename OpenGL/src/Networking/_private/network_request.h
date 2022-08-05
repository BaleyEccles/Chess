//
// Created by Skyla on 28/7/2022.
//

#ifndef NETWORKINGTESTS_NETWORK_REQUEST_H
#define NETWORKINGTESTS_NETWORK_REQUEST_H

#include "../chess_networking.h"

std::pair<std::string, unsigned int> network_request(std::string method, std::string url);

struct Method {
    static std::string GET;
    static std::string POST;
    static std::string PUT;
    static std::string _DELETE;
};

#endif //NETWORKINGTESTS_NETWORK_REQUEST_H