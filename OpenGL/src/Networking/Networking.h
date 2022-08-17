#include "chess_networking.h"

#include <iostream>
#include "Peices/PeicesMain.h"
#include <fstream>
#include "json.hpp"
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
using json = nlohmann::json;

class Networking
{
public:
	Networking();
	~Networking();

	void Main(std::vector<Peices*> Peices);

	void CreateJSON(std::vector<Peices*> Peices);

	json ReadJSON();

	void GetRequest();
	void PostRequest();
	std::string Join_Create;

	std::string URL;
	std::string InviteID;
	unsigned int InviteID_get;
	Invite InviteMain;

private:



};