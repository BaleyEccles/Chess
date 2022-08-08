//
// Created by Skyla on 27/7/2022.
//

#include "game.h"

std::string Game::fetch_game() const {
	const std::string url = server_url + "invite/" + game_id;
	try {
		std::pair<std::string, unsigned int> request = network_request(Method::GET, url);

		return request.first;

	} catch (const std::exception& e) {
		std::cerr << "Request failed, error: " << e.what() << '\n';
		throw e;
	}
}

unsigned int Game::save_game(std::string json) const {
	const std::string url = server_url + "invite/";

	try {

		http::Request request{url};
		const auto response = request.send(Method::POST, json, {
				{"Content-Type", "application/json"}
		});

		return response.status.code;

	} catch (const std::exception& e) {
		std::cerr << "Request failed, error: " << e.what() << '\n';
		throw e;
	}
}

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