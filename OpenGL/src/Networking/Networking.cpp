#include "Networking.h"

Networking::Networking()
{
    /*
    std::string Location;
    std::cout << "Please input the loctaion of the server: ";
    std::cin >> Location;
    http::Request Request{ Location };
    request = &Request;*/
}

Networking::~Networking()
{
}

void Networking::CreateJSON(std::vector<Peices*> Peices)
{
    json JSON;
    for (int i = 0; i < Peices.size(); i++)
    {
        JSON["Pieces"][Peices[i]->Type + std::to_string(i)] = {{"XPosistion", Peices[i]->Game_Pos.x}, {"YPosistion", Peices[i]->Game_Pos.y}, {"Colour", Peices[i]->Colour}, {"IsDead", Peices[i]->IsDead} };
    }
    std::ofstream file("Send.json");
    file << JSON;
    file.close();
}

void Networking::ReadJSON()
{
    std::ifstream myFile("Receive.json");
    std::ostringstream tmp;
    tmp << myFile.rdbuf();
    std::string JSONFile = tmp.str();
    json data = json::parse(JSONFile);
    //can be used to access the data in the json file
    //data.at("Pieces").at("Pawn10").at("IsDead")
}

void Networking::GetRequest()
{
    /*
    try
    {
        // you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
        http::Request request{ "http://test.com/test" };

        // send a get request
        const auto response = request.send("GET");
        std::cout << std::string{ response.body.begin(), response.body.end() } << '\n'; // print the result
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }*/
    
}

void Networking::PostRequest()
{
    /*try
    {
        http::Request request{ "http://test.com/test" };
        const std::string body = "{\"foo\": 1, \"bar\": \"baz\"}";
        const auto response = request.send("POST", parameters, {
            {"Content-Type", "application/json"}
            });
        std::cout << std::string{ response.body.begin(), response.body.end() } << '\n'; // print the result
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }*/
}
