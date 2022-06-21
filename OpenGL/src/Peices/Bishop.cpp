#pragma once
#include "PeicesMain.h"

Bishop::Bishop(glm::vec2 Location, std::string colour)
    :Peices(Location, colour, "Bishop")
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


std::vector<glm::vec2> Bishop::GetAvalibleMoves()
{
    std::vector<glm::vec2> Moves;
    // diagonal

    bool FirstPos = true;
    // diagonal
    FirstPos = true;
    for (int k = 1; k < 16; k++)
    {
        if (CheckPosIsOccupied(glm::vec2(Game_Pos.x + (float)k, Game_Pos.y + (float)k)) && FirstPos)
        {
            FirstPos = false;
            Moves.push_back(glm::vec2(Game_Pos.x + (float)k, Game_Pos.y + (float)k));
        }
        else {
            if (FirstPos)
            {
                Moves.push_back(glm::vec2(Game_Pos.x + (float)k, Game_Pos.y + (float)k));
            }
        }
    }
    FirstPos = true;
    for (int k = 1; k < 16; k++)
    {
        if (CheckPosIsOccupied(glm::vec2(Game_Pos.x - (float)k, Game_Pos.y + (float)k)) && FirstPos)
        {
            FirstPos = false;
            Moves.push_back(glm::vec2(Game_Pos.x - (float)k, Game_Pos.y + (float)k));

        }
        else {
            if (FirstPos)
            {
                Moves.push_back(glm::vec2(Game_Pos.x + -(float)k, Game_Pos.y + (float)k));
            }
        }
    }
    FirstPos = true;
    for (int k = 1; k < 16; k++)
    {
        if (CheckPosIsOccupied(glm::vec2(Game_Pos.x + (float)k, Game_Pos.y - (float)k)) && FirstPos)
        {
            FirstPos = false;
            Moves.push_back(glm::vec2(Game_Pos.x + (float)k, Game_Pos.y - (float)k));
        }
        else {
            if (FirstPos)
            {
                Moves.push_back(glm::vec2(Game_Pos.x + (float)k, Game_Pos.y + -(float)k));
            }
        }
    }
    FirstPos = true;
    for (int k = 1; k < 16; k++)
    {
        if (CheckPosIsOccupied(glm::vec2(Game_Pos.x - (float)k, Game_Pos.y - (float)k)) && FirstPos)
        {

            FirstPos = false;

            Moves.push_back(glm::vec2(Game_Pos.x - (float)k, Game_Pos.y - (float)k));
        }
        else {
            if (FirstPos)
            {
                Moves.push_back(glm::vec2(Game_Pos.x - (float)k, Game_Pos.y - (float)k));
            }
        }
    }

    return Moves;
}
