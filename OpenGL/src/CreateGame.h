
#pragma once
#include "vendor/glm/glm.hpp"
#include "globals.cpp"
#include "RenderItem.h"
//#include <Windows.h>
#include <cmath>
#include "Peices/PeicesMain.h"
#include <vector>

struct CheckVaribles{
	bool IsInCheck = false;
	std::string ColourInCheck;
	int KingVecPos;
	int CheckPieceVecPos;

	glm::vec2 CheckPiecePos;
	glm::vec2 KingPos;
	std::string CheckPieceType;
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
	int MoveNumber = -32;

	void CheckPromotion();

	bool IsInVec(glm::vec2 i, glm::vec2 pos);

private:



};