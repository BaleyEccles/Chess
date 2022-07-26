//#include "HTTPRequest.hpp"
#include <iostream>
#include "json.hpp"
#include "CreateGame.h"
#include <fstream>

using json = nlohmann::json;

class Networking
{
public:
	Networking();
	~Networking();

	void CreateJSON(std::vector<Peices*> Peices);

	void ReadJSON();

	void GetRequest();
	void PostRequest();

	//http::Request* request;

private:




};