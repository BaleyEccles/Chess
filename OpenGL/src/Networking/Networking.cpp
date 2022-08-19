#include "Networking.h"

Networking::Networking()
{
    /*
    //std::cout << "please input the server url \n";
    //std::cin >> URL;
    std::string self_or_network = "s";
    std::cout << "Would you like to play localy or though the network (l or n)\n";
    std::cin >> self_or_network;
    std::string text;
    std::string url;


    
    
    //system("clear");//Clearing previous logs so that the result can be seen neatly
    //std::string res;
    //std::ifstream file("data.json");//Retrieving response from data.txt
    //while (getline(file, res)) {
    //    std::cout << res;
    //}
    //file.close();
    
    if (self_or_network == "n")
    {
        InviteMain.server_url = "http://api.alessian.org/";
        bool is_jc = true;
        std::cout << "Join or Create Game. (j or c)\n";
        std::cin >> Join_Create;
        if (Join_Create == "c")
        {
            url = "curl -X POST http://api.alessian.org/invite";
            //url = "curl -v --header \"Content-Type: application/json\" -d @Send.json http://api.alessian.org/invite";
            //     curl -v --header "Content-Type: application/json" -d "{\"value\":\"node JS\"}" http://api.alessian.org/

            //InviteID = system(url.c_str());//Executing script
            
            std::array<char, 128> buffer;
            std::string result;
            std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(url.c_str(), "r"), _pclose);
            if (!pipe) {
                throw std::runtime_error("popen() failed!");
            }
            while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
                result += buffer.data();
            }
            InviteID = result;
            std::cout <<"invite id :" << InviteID << std::endl;

        }
        if (Join_Create == "j")
        {
            std::cout << "Input the invite ID:" << std::endl;
            std::cin >> InviteID_get;

            url = "curl http://api.alessian.org/invite/" + InviteID_get;
            //url = "curl -v --header \"Content-Type: application/json\" -d @Send.json http://api.alessian.org/invite";
            //     curl -v --header "Content-Type: application/json" -d "{\"value\":\"node JS\"}" http://api.alessian.org/


            //std::cout << "dsad" << std::endl;
            system(url.c_str());//Executing script

        }
            /*
        while (is_jc)
        {

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
        //InviteMain.check_for_partner(InviteID_get);
    }
    */
}



Networking::~Networking()
{
}

void Networking::Main(std::vector<Peices*> Peices)
{
    CreateJSON(Peices);
}

void Networking::CreateJSON(std::vector<Peices*> Peices)
{
    //json JSON;
    //for (int i = 0; i < Peices.size(); i++)
    //{
    //    JSON["Pieces"][Peices[i]->Type + std::to_string(i)] = {{"XPosistion", Peices[i]->Game_Pos.x}, {"YPosistion", Peices[i]->Game_Pos.y}, {"Colour", Peices[i]->Colour}, {"IsDead", Peices[i]->IsDead} };
    //}
    //std::ofstream file("Send.json");
    //file << JSON;
    ////std::cout << JSON << std::endl;
    //file.close();
    //PostRequest();
    //GetRequest();
    //ReadJSON();
}

json Networking::ReadJSON()
{
    std::ifstream myFile("Receive.json");
    std::ostringstream tmp;
    tmp << myFile.rdbuf();
    std::string JSONFile = tmp.str();
    json data = json::parse(JSONFile);
    //std::cout << data << std::endl;
    myFile.close();
    return data;
    //can be used to access the data in the json file
    //data.at("Pieces").at("Pawn10").at("IsDead")
}

void Networking::GetRequest()
{
    //  curl -i -H "Accept: application/json" 'server:5050/a/c/getName{"param0":"pradeep"}'
    std::string text = "curl http://api.alessian.org/invite/" + InviteID;    
    std::string url = text + " -H \"Accept: application/json\"";
    //url = "curl -o data.json " + url;//Adding the CURL command to the URL (I save the result in a file called data.txt)
    system(url.c_str());//Executing script
    //system("clear");//Clearing previous logs so that the result can be seen neatly
    std::string res;
    std::ifstream file("Receive.json");//Retrieving response from data.txt
    //while (getline(file, res)) {
    //    std::cout << res;
    //}
    file.close();
    //remove("data.txt");//Deleting file after the output is shown
    std::cout << "\nDone\n";//Voila
    
}

void Networking::PostRequest()
{
    
    std::string text = "curl - X POST http ://api.alessian.org/invite/" + InviteID;
    std::string url = text + " -H \"Content-Type: application/json\" -d @Send.json ";
    ;


    //std::cout << gethostname() << std::endl;



    /*
    curl -X POST https://reqbin.com/echo/post/json
   -H 'Content-Type: application/json'
   -d '{"login":"my_login","password":"my_password"}'
    
    
    */
    //url = "curl --help all";




    std::cout << "dsad" << std::endl;



    system(url.c_str());//Executing script

    //system("clear");//Clearing previous logs so that the result can be seen neatly
    std::string res;
    std::ifstream file("data.json");//Retrieving response from data.txt
    //while (getline(file, res)) {
    //    std::cout << res;
    //}
    file.close();
    //remove("data.txt");//Deleting file after the output is shown
    //std::cout << "\nDone\n";//Voila
    
    
}
