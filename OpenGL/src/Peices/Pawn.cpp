#include "PeicesMain.h"

Pawn::Pawn(glm::vec2 Location, std::string colour)
    :Peices(Location, colour, "Pawn")
{
    hwnd = FindWindowA(NULL, "NameNoWindowWillUse");
    position = Location;
    Game_Pos = Location;
    std::vector<float> CubeData;
    std::vector<unsigned int> Floats = { 2, 2, 4 };
    float colourR = 0.0f;
    float colourG = 0.0f;
    float colourB = 0.0f;
    float colourA = 0.0f;
    int i = 0;
    int j = 0;
    CubeData = { 
        +XCoordData, -YCoordData, 1.0f, 0.0f, colourR, colourG, colourB, colourA,
        +XCoordData, +YCoordData, 1.0f, 1.0f, colourR, colourG, colourB, colourA,
        -XCoordData, +YCoordData, 0.0f, 1.0f, colourR, colourG, colourB, colourA,
        -XCoordData, -YCoordData, 0.0f, 0.0f, colourR, colourG, colourB, colourA
    };

    Peice.AddData(CubeData, Floats);
}

std::vector<glm::vec2> Pawn::GetAvalibleMoves()
{
    //std::cout << "pawn" << std::endl;

    std::vector<glm::vec2> Moves;
    if (Colour == "BLACK")
    {
        Moves.push_back(glm::vec2(Game_Pos.x, Game_Pos.y - 1.0f));

    }
    if (Colour == "WHITE")
    {
        Moves.push_back(glm::vec2(Game_Pos.x, Game_Pos.y + 1.0f));
    }

    return Moves;
}