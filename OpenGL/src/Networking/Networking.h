#include <iostream>
#include "json.hpp"
#include "Peices/PeicesMain.h"
#include <fstream>


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

	std::string URL;
	std::string InviteID;

private:




};