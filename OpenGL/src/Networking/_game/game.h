//
// Created by Skyla on 27/7/2022.
//

#ifndef CHESSNETWORKING_GAME_H
#define CHESSNETWORKING_GAME_H

#include "../chess_networking.h"
#include "../_private/network_request.h"

struct Game {

    std::string game_id;

    std::string server_url;

    void fetch_game();

    void create_game();

    void save_game();

    unsigned int quit_game(unsigned int server_url) const;
};

#endif //CHESSNETWORKING_GAME_H
