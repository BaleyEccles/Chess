//
// Created by Skyla on 27/7/2022.
//
#include "invite.h"

std::pair<std::string, unsigned int> Invite::fetch_invite(unsigned int invite_id) const {
	const std::string url = server_url + "invite/" + std::to_string(invite_id);

	try {
		return network_request(Method::GET, url);

	} catch (const std::exception& e) {
		std::cerr << "Request failed, error: " << e.what() << '\n';
		throw e;
	}
}

std::pair<unsigned int, unsigned int> Invite::create_invite() const {
	const std::string url = server_url + "invite/";

	try {
		std::pair<std::string, unsigned int> results = network_request(Method::POST, url);
		return {std::stoi(results.first), results.second};

	} catch (const std::exception& e) {
		std::cerr << "Request failed, error: " << e.what() << '\n';
		throw e;
	}
}

unsigned int Invite::delete_invite(unsigned int invite_id) const {
	const std::string url = server_url + "invite/" + std::to_string(invite_id);

	try {
		std::pair<std::string, unsigned int> results = network_request(Method::_DELETE, url);
		return results.second;

	} catch (const std::exception& e) {
		std::cerr << "Request failed, error: " << e.what() << '\n';
		throw e;
	}
}

std::string Invite::check_for_partner(unsigned int invite_id) const {
	const std::string url = server_url + "invite/" + std::to_string(invite_id);

	while (true) {
		try {
			std::pair<std::string, unsigned int> results = network_request(Method::PUT, url);
			return results.first;

		} catch (const std::exception& e) {
			std::cerr << "Request failed, error: " << e.what() << '\n';
			throw e;
		}
	}
}