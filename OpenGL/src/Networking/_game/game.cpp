//
// Created by Skyla on 27/7/2022.
//
#include "game.h"

void Game::create_game() {}

void Game::fetch_game() {}

unsigned int Game::quit_game(unsigned int invite_id) const {
    const std::string url = server_url + "game/" + std::to_string(invite_id);

    try {
        std::pair<std::string, unsigned int> results =  network_request(Method::_DELETE, url);
        return results.second;

    } catch (const std::exception& e) {
        std::cerr << "Request failed, error: " << e.what() << '\n';
        throw e;
    }
}

void Game::save_game() {}