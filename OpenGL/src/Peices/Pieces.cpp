#include "Peices\Pieces.h"

Peices::Peices(glm::vec2 Location, std::string colour, std::string PeiceType)
    :Peice("res/shaders/Peice.shader", (colour == "WHITE") ? "res/textures/" + PeiceType + "_w.png" : "res/textures/" + PeiceType + "_b.png"), Colour(colour), Type(PeiceType), CellMove("res/shaders/Peice.shader", "res/textures/CanMoveTo.png")
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
    CellMove.AddData(CubeData, Floats);

}

bool Peices::IsOutOfBoard(glm::vec2 Pos)
{
    if (Pos.y > 7)
    {
        return true;
    }
    if (Pos.y < 0)
    {
        return true;
    }
    if (Pos.x > 7)
    {
        return true;
    }
    if (Pos.x < 0)
    {
        return true;
    }
    return false;
}


void Peices::GetMousePos()
{
    POINT Point;
    GetCursorPos(&Point);

    RECT rect = { NULL };
    POINT PD;
    if (GetWindowRect(hwnd, &rect)) {
        PD.x = rect.left;
        PD.y = rect.top;
    };
    MousePos.x = Point.x - PD.x;
    MousePos.y = Windowy - (Point.y - PD.y) + 56;

    //std::cout << MousePos.x << "  " << MousePos.y << std::endl;

}

void Peices::GetPosScreen()
{
    position_screen.x = position.x * (Windowx / 8.0f) + (Windowx / 16.0f);
    position_screen.y = position.y * (Windowy / 8.0f) + (Windowy / 16.0f);
    //std::cout << position_screen.x << "  " << position_screen.y << std::endl;
}

bool Peices::CheckMouseCollison()
{
    if ((GetKeyState(VK_LBUTTON) & 0x8000) != 0)
    {
        if (MousePos.x < position_screen.x + (Windowx / 16.0f) &&
            MousePos.x > position_screen.x - (Windowx / 16.0f) &&
            MousePos.y < position_screen.y + (Windowy / 16.0f) &&
            MousePos.y > position_screen.y - (Windowy / 16.0f))
        {
            IsHeld = true;
            return true;
        }
    }
    IsHeld = false;
    return false;
}

void Peices::SetPosToMouse()
{
    position.x = (MousePos.x / (Windowx / 8.0f)) - (Windowx / 16.0f) / (Windowx / 8.0f);
    position.y = (MousePos.y / (Windowy / 8.0f)) - (Windowy / 16.0f) / (Windowy / 8.0f);
    //std::cout << Windowx << std::endl;
}

void Peices::Main(std::vector<Peices*> PeiceVec)
{
    PeiceVecMain = PeiceVec;
    if (!IsDead)
    {
        Render();
        Location();
    }
}


void Peices::UpdateAvailableMoves()
{
    GetAvalibleMoves();
    RemoveSamePeice();
}



void Peices::Location()
{
    GetMousePos();
    GetPosScreen();

    // checks if other piece is held
    bool IsOtherPeiceHeld = false;
    if (!IsHeld)
    {
        for (int i = 0; i < PeiceVecMain.size(); i++)
        {
            if (PeiceVecMain[i]->IsHeld == true)
            {
                IsOtherPeiceHeld = true;
            }
        }
    }
    //

    if (CanGo && !IsOtherPeiceHeld)
    {
        if (CheckMouseCollison())
        {
            SetPosToMouse();
        }
        if (!CheckMouseCollison())
        {
            SetPosToCell();
        }
    }
}

void Peices::Render()
{
    Peice.Render(floor(position).x, floor(position).y);
    Peice.Render(position.x, position.y);
    if (IsHeld)
    {
        for (int i = 0; i < AvailableMoves.size(); i++)
        {
            CellMove.Render(AvailableMoves[i].x, AvailableMoves[i].y);
        }
    }

}



void Peices::SetPosToCell()
{
    if (CheckMove(floor(position)))
    {
        position = floor(position);
        Game_Pos = position;
        HasMoved = true;
        CheckTakePeice();
    }
    if (!CheckMove(floor(position)))
    {
        position = Game_Pos;
    }
}

bool Peices::CheckMove(glm::vec2 Pos)
{

    if (IsOutOfBoard(Pos))
    {
        return false;
    }
    for (int i = 0; i < AvailableMoves.size(); i++)
    {
        if (AvailableMoves[i] == Pos)
        {
            return true;
        }
    }
    return false;
}

bool Peices::CheckPosIsOccupied(glm::vec2 Pos)
{
    for (int i = 0; i < PeiceVecMain.size(); i++)
    {
        if (floor(PeiceVecMain[i]->Game_Pos) == floor(Pos))
        {
            /*if (PeiceVecMain[i]->Type == "King" && PeiceVecMain[i]->Colour != Colour)
            {
                return false;
            }
            else
            {*/
            return true;
            //}
        }
    }
    return false;
}

void Peices::CheckTakePeice()
{

    for (int i = 0; i < PeiceVecMain.size(); i++)
    {
        if (PeiceVecMain[i]->Game_Pos == Game_Pos && PeiceVecMain[i]->Colour != Colour)
        {
            PeiceVecMain[i]->IsDead = true;
        }
    }
}

void Peices::RemoveSamePeice()
{
    std::vector<int> PosDel;
    for (int i = 0; i < AvailableMoves.size(); i++)
    {
        for (int k = 0; k < PeiceVecMain.size(); k++)
        {
            if (AvailableMoves[i] == PeiceVecMain[k]->Game_Pos && Colour == PeiceVecMain[k]->Colour && PeiceVecMain[k]->IsDead == false)
            {
                PosDel.push_back(i);
            }
        }
    }
    for (int l = 0; l < PosDel.size(); l++) {
        AvailableMoves.erase(AvailableMoves.begin() + PosDel[l]);
        for (int j = 0; j < PosDel.size(); j++)
        {
            PosDel[j] -= 1;
        }
    }
    PosDel.clear();
    for (int i = 0; i < AvailableMoves.size(); i++)
    {
        if (AvailableMoves[i].x < 0 || AvailableMoves[i].x > 7 || AvailableMoves[i].y < 0 || AvailableMoves[i].y > 7)
        {
            PosDel.push_back(i);
        }
    }
    for (int l = 0; l < PosDel.size(); l++) {
        AvailableMoves.erase(AvailableMoves.begin() + PosDel[l]);
        for (int j = 0; j < PosDel.size(); j++)
        {
            PosDel[j] -= 1;
        }
    }
}

void Peices::GetAvalibleMoves()
{
}

