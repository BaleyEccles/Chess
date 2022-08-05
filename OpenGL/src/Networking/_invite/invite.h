//
// Created by Skyla on 27/7/2022.
//
#ifndef CHESSNETWORKING_INVITE_H
#define CHESSNETWORKING_INVITE_H

#include "../chess_networking.h"
#include "../_private/network_request.h"

class Invite {
private:
    std::string game_id;
public:
    std::string server_url;

    /// game_id : Status Code
    std::pair<std::string, unsigned int> fetch_invite(unsigned int invite_id) const;

    /// Invite ID : Status Code
    std::pair<unsigned int, unsigned int> create_invite() const;

    /// Status code
    unsigned int delete_invite(unsigned int invite_id) const;

    /// game_id
    std::string check_for_partner(unsigned int invite_id) const;
};

#endif //CHESSNETWORKING_INVITE_H
