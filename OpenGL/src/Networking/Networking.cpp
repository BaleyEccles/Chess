#include "Networking.h"

Networking::Networking()
{
    
    //std::cout << "please input the server url \n";
    //std::cin >> URL;
    
    InviteMain.server_url = "http://test/";
    bool is_jc = true;
    while (is_jc)
    {
        std::cout << "Join or Create Game. (j or c)\n";
        std::cin >> Join_Create;
        if (Join_Create == "c")
        {
            InviteID = InviteMain.create_invite();
            std::cout << "Your invite Code is: " + InviteID.first << std::endl;
            InviteID_get = InviteID.first;
            is_jc = false;
        }
        if (Join_Create == "j")
        {
            std::cout << "Input the invite ID:" << std::endl;
            std::cin >> InviteID_get;
            InviteMain.fetch_invite(InviteID_get);
            is_jc = false;

        }
        if (Join_Create != "c" || "j")
        {
            is_jc = true;
        }

    }
    InviteMain.check_for_partner(InviteID_get);
    

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
    //std::cout << JSON << std::endl;
    file.close();

}

json Networking::ReadJSON()
{
    std::ifstream myFile("Receive.json");
    std::ostringstream tmp;
    tmp << myFile.rdbuf();
    std::string JSONFile = tmp.str();
    json data = json::parse(JSONFile);
    std::cout << data << std::endl;
    return data;
    //can be used to access the data in the json file
    //data.at("Pieces").at("Pawn10").at("IsDead")
}

void Networking::GetRequest()
{
    /*
    std::string text;
    //getline(cin, url);
    std::string url = "147.41.128.35";
    url = "curl -o data.json " + url;//Adding the CURL command to the URL (I save the result in a file called data.txt)
    system(url.c_str());//Executing script
    //system("clear");//Clearing previous logs so that the result can be seen neatly
    std::string res;
    std::ifstream file("data.json");//Retrieving response from data.txt
    while (getline(file, res)) {
        std::cout << res;
    }
    file.close();
    //remove("data.txt");//Deleting file after the output is shown
    std::cout << "\nDone\n";//Voila
    */
}

void Networking::PostRequest()// todo check if two pc can connect via ip
{
    /*
    std::string text;
    std::string url;


    //std::cout << gethostname() << std::endl;


    url = "curl -X POST -d @Send.json 10.5.146.137";
    url = "curl -v --header \"Content-Type: application/json\" -d @Send.json http://localhost:3000/test";
    //     curl -v --header "Content-Type: application/json" -d "{\"value\":\"node JS\"}" http://localhost:3000/test


    //url = "curl --help all";




    std::cout << "dsad" << std::endl;



    system(url.c_str());//Executing script
    //system("clear");//Clearing previous logs so that the result can be seen neatly
    /*std::string res;
    std::ifstream file("data.json");//Retrieving response from data.txt
    while (getline(file, res)) {
        std::cout << res;
    }
    file.close();
    //remove("data.txt");//Deleting file after the output is shown*/
    //std::cout << "\nDone\n";//Voila
    
    
}
