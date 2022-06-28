#include "CreateGame.h"

CreateGame::CreateGame()
{

	std::vector<Pawn*> Pawns;
	for (int i = 0; i < 16; ++i) 
	{
		if (i < 8)
		{
			Pawns.push_back(new Pawn(glm::vec2((float)i, 1.0f), "WHITE"));
		}
		else
		{
			Pawns.push_back(new Pawn(glm::vec2((float)i - 8.0f, 6.0f), "BLACK"));
		}
	}
	for (int i = 0; i < Pawns.size(); i++)
	{
		Peices.push_back(Pawns[i]);
	}
	
	Rook* Rook1 = new Rook(glm::vec2(7.0f, 7.0f), "BLACK");
	Peices.push_back(Rook1);
	Rook* Rook2 = new Rook(glm::vec2(0.0f, 7.0f), "BLACK");
	Peices.push_back(Rook2);

	Rook* Rook3 = new Rook(glm::vec2(7.0f, 0.0f), "WHITE");
	Peices.push_back(Rook3);
	Rook* Rook4 = new Rook(glm::vec2(0.0f, 0.0f), "WHITE");
	Peices.push_back(Rook4);

	Queen* Queen1 = new Queen(glm::vec2(4.0f, 0.0f), "WHITE");
	Peices.push_back(Queen1);
	Queen* Queen2 = new Queen(glm::vec2(4.0f, 7.0f), "BLACK");
	Peices.push_back(Queen2);

	Bishop* Bishop1 = new Bishop(glm::vec2(2.0f, 0.0f), "WHITE");
	Peices.push_back(Bishop1);
	Bishop* Bishop2 = new Bishop(glm::vec2(5.0f, 0.0f), "WHITE");
	Peices.push_back(Bishop2);

	Bishop* Bishop3 = new Bishop(glm::vec2(2.0f, 7.0f), "BLACK");
	Peices.push_back(Bishop3);
	Bishop* Bishop4 = new Bishop(glm::vec2(5.0f, 7.0f), "BLACK");
	Peices.push_back(Bishop4);

	Knight* Knight1 = new Knight(glm::vec2(1.0f, 0.0f), "WHITE");
	Peices.push_back(Knight1);
	Knight* Knight2 = new Knight(glm::vec2(6.0f, 0.0f), "WHITE");
	Peices.push_back(Knight2);

	Knight* Knight3 = new Knight(glm::vec2(1.0f, 7.0f), "BLACK");
	Peices.push_back(Knight3);
	Knight* Knight4 = new Knight(glm::vec2(6.0f, 7.0f), "BLACK");
	Peices.push_back(Knight4);
	
	King* King1 = new King(glm::vec2(3.0f, 0.0f), "WHITE");
	Peices.push_back(King1);

	King* King2 = new King(glm::vec2(3.0f, 7.0f), "BLACK");
	Peices.push_back(King2);

}

void CreateGame::LoadData()
{

	//Peices = ;
}


void CreateGame::Main()
{
	LoadData();
	for (int i = 0; i < Peices.size(); i++)
	{
		if (CurrentMove == Peices[i]->Colour)
		{
			Peices[i]->CanGo = true;
		}
		else
		{
			Peices[i]->CanGo = false;
		}
		if (CheckIfInCheck())
		{
			for (int b = 0; b < Peices.size(); b++)
			{
				if (Peices[b]->Type != "King" && Peices[b]->Colour == CurrentMove)
				{

					Peices[b]->CanGo = false;
				}
			}
		}
		Peices[i]->Main(Peices);

		//RemoveDeadPeices();
		if (Peices[i]->HasMoved == true)
		{
			for (int k = 0; k < Peices.size(); k++)
			{
				Peices[k]->UpdateAvailableMoves();
			}
			SwapSide();
		}
		Peices[i]->HasMoved = false;
	}
}

bool CreateGame::CheckIfInCheck()
{
	
	glm::vec2 KingWPos;
	glm::vec2 KingBPos;
	for (int k = 0; k < Peices.size(); k++)
	{
		if (Peices[k]->Type == "King")
		{
			if (Peices[k]->Colour == "BLACK")
			{
				KingBPos = Peices[k]->Game_Pos;
			}
			if (Peices[k]->Colour == "WHITE")
			{
				KingWPos = Peices[k]->Game_Pos;
			}
		}
	}
	for (int l = 0; l < Peices.size(); l++)
	{
		if (Peices[l]->Type != "King" && Peices[l]->Colour == "BLACK")
		{
			for (int i = 0; i < Peices[l]->AvailableMoves.size(); i++)
			{
				if (Peices[l]->AvailableMoves[i] == KingWPos)
				{
					// White is in check
					return true;
				}
			}
		}
		if (Peices[l]->Type != "King" && Peices[l]->Colour == "WHITE")
		{
			for (int i = 0; i < Peices[l]->AvailableMoves.size(); i++)
			{
				if (Peices[l]->AvailableMoves[i] == KingBPos)
				{
					// Black is in check
					return true;
				}
			}
		}
	}
	return false;

}


void CreateGame::SwapSide()
{
	if (CurrentMove == "WHITE")
	{
		CurrentMove = "BLACK";
		return;
	}
	if (CurrentMove == "BLACK")
	{
		CurrentMove = "WHITE";
		return;
	}
}

void CreateGame::RemoveDeadPeices()
{

	for (int i = 0; i < Peices.size(); i++)
	{
		int posdel = -1;
		for (int i = 0; i < Peices.size(); i++)
		{
			if (Peices[i]->IsDead)
			{
				posdel = i;
			}
		}
		if (posdel != -1)
		{
			Peices.erase(Peices.begin() + posdel);

		}
	}
}
