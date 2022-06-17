#pragma once
#include "PeicesMain.h"

Knight::Knight(glm::vec2 Location, std::string colour)
    :Peices(Location, colour, "Knight")
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


std::vector<glm::vec2> Knight::GetAvalibleMoves()
{
    std::vector<glm::vec2> Moves;

    Moves.push_back(glm::vec2(Game_Pos.x + 2.0f, Game_Pos.y + 1.0f));
    Moves.push_back(glm::vec2(Game_Pos.x + 1.0f, Game_Pos.y + 2.0f));
    Moves.push_back(glm::vec2(Game_Pos.x + 2.0f, Game_Pos.y - 1.0f));
    Moves.push_back(glm::vec2(Game_Pos.x - 2.0f, Game_Pos.y + 1.0f));
    Moves.push_back(glm::vec2(Game_Pos.x - 2.0f, Game_Pos.y - 1.0f));
    Moves.push_back(glm::vec2(Game_Pos.x + 1.0f, Game_Pos.y - 2.0f));
    Moves.push_back(glm::vec2(Game_Pos.x - 1.0f, Game_Pos.y + 2.0f));
    Moves.push_back(glm::vec2(Game_Pos.x - 1.0f, Game_Pos.y - 2.0f));

    return Moves;
}
