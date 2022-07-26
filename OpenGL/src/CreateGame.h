
#pragma once
#include "vendor/glm/glm.hpp"
#include "globals.cpp"
#include <vector>
#include "RenderItem.h"
#include <Windows.h>
#include <cmath>
#include "Peices/PeicesMain.h"

struct CheckVaribles{
	bool IsInCheck = false;
	std::vector<glm::vec2> CheckMoves;
};


class CreateGame
{
public:

	CreateGame();

	void LoadData();	

	std::vector<Peices*> Peices;


	void Main();

	std::string CurrentMove = "WHITE";

	void SwapSide();
	CheckVaribles CheckIfInCheck();

	void RemoveDeadPiece();
private:



};