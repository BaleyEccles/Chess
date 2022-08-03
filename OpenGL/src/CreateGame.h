
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

	void LoadData(std::vector<Peices*> Data);

	std::vector<Peices*> Pieces;
	std::vector<Peices*> DefaultStart;


	void Main();

	std::string CurrentMove = "WHITE";

	void SwapSide();
	CheckVaribles CheckIfInCheck();

	void DealWithCheck(CheckVaribles CheckVar);
	void RestartGame();

	void RemoveDeadPiece();
private:



};