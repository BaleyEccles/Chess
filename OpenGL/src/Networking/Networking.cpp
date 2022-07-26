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
        JSON["Pieces"][Peices[i]->Type + std::to_string(i)] = {{"XPosistion", Peices[i]->Game_Pos.x}, {"YPosistion", Peices[i]->Game_Pos.y}, {"Colour", Peices[i]->Colour}};
    }

}

void Networking::ReadJSON()
{
    std::ifstream f("example.json");
    json data = json::parse(f);
}

void Networking::GetRequest()
{
    /*
    try
    {

        // send a get request
        const auto response = request->send("GET");
        std::cout << std::string{ response.body.begin(), response.body.end() } << '\n'; // print the result
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }*/
}

void Networking::PostRequest()
{
    /*
    try
    {
        const std::string body = "{\"foo\": 1, \"bar\": \"baz\"}";
        const auto response = request->send("POST", body, {
            {"Content-Type", "application/json"}
            });
        std::cout << std::string{ response.body.begin(), response.body.end() } << '\n'; // print the result
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }*/
}
