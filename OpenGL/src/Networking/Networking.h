#include "chess_networking.h"

#include <iostream>
#include "Peices/PeicesMain.h"
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

class Networking
{
public:
	Networking();
	~Networking();

	void CreateJSON(std::vector<Peices*> Peices);

	json ReadJSON();

	void GetRequest();
	void PostRequest();
	std::string Join_Create;

	std::string URL;
	std::pair<unsigned int, unsigned int> InviteID;
	unsigned int InviteID_get;
	Invite InviteMain;

private:



};