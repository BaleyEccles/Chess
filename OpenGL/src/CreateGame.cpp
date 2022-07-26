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
	RemoveDeadPiece();
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

		CheckVaribles CheckVaribles = CheckIfInCheck();

		if (CheckVaribles.IsInCheck)
		{
			for (int b = 0; b < Peices.size(); b++)
			{
				if (Peices[b]->Type != "King" && Peices[b]->Colour == CurrentMove)
				{
					for (int u = 0; u < Peices[b]->AvailableMoves.size(); u++)
					{
						bool CanGo = false;
						
						for (int g = 0; g < CheckVaribles.CheckMoves.size(); g++)
						{
							if (Peices[b]->AvailableMoves[u] == CheckVaribles.CheckMoves[g])
							{
								CanGo = true;
							}
							else
							{
								if (!CanGo)
								{
									CanGo = false;
								}
							}
						}
						Peices[b]->CanGo = CanGo;

					}

				}

				for (int b = 0; b < Peices.size(); b++)
				{
					std::vector<int> PosDel;

					if (Peices[b]->Type != "King" && Peices[b]->Colour == CurrentMove && Peices[b]->CanGo == true)
					{
						for (int g = 0; g < CheckVaribles.CheckMoves.size(); g++)
						{
							for (int u = 0; u < Peices[b]->AvailableMoves.size(); u++)
							{
								if (CheckVaribles.CheckMoves[g] != Peices[b]->AvailableMoves[u])
								{
									PosDel.push_back(u);

								}
							}
						}
					}
					for (int h = 0; h < PosDel.size(); h++)
					{
						for (int y = 0; y < PosDel.size(); y++)
						{
							if (y != h)
							{
								if (PosDel[y] == PosDel[h])
								{
									PosDel.erase(PosDel.begin() + y);
									y--;
								}
							}
						}
					}
					for (int z = 0; z < PosDel.size(); z++)
					{
						Peices[b]->AvailableMoves.erase(Peices[b]->AvailableMoves.begin() + PosDel[z]);

						for (int j = 0; j < PosDel.size(); j++)
						{

							PosDel[j] -= 1;
						}
					}
					PosDel.clear();
				}
			}
		}
		for (int b = 0; b < Peices.size(); b++)
		{
			if (Peices[b]->Type == "King" && Peices[b]->Colour == CurrentMove)
			{
				std::vector<int> PosDel;

				for (int p = 0; p < Peices[b]->AvailableMoves.size(); p++)
				{
					for (int a = 0; a < Peices.size(); a++)
					{
						if (Peices[a]->Colour != CurrentMove)
						{
							if (Peices[b] != Peices[a])
							{
								for (int k = 0; k < Peices[a]->AvailableMoves.size(); k++)
								{
									if (Peices[a]->AvailableMoves[k] == Peices[b]->AvailableMoves[p])
									{
										PosDel.push_back(p);
									}
								}
							}
						}
					}
				}


				for (int z = 0; z < PosDel.size(); z++)
				{
					Peices[b]->AvailableMoves.erase(Peices[b]->AvailableMoves.begin() + PosDel[z]);

					for (int j = 0; j < PosDel.size(); j++)
					{

						PosDel[j] -= 1;
					}
				}
				PosDel.clear();

			}
		}
		
		Peices[i]->Main(Peices);

		if (Peices[i]->HasMoved == true)
		{
			

			//std::cout << i << std::endl;
			for (int k = 0; k < Peices.size(); k++)
			{
				Peices[k]->UpdateAvailableMoves();
			}
			SwapSide();
		}
		Peices[i]->HasMoved = false;
	}
}

CheckVaribles CreateGame::CheckIfInCheck()
{
	CheckVaribles CheckVariblesMain;

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
					Peices[l]->GetAvalibleMoves();
					CheckVariblesMain.CheckMoves = Peices[l]->AvailableMoves;

					// White is in check
					CheckVariblesMain.IsInCheck = true;
				}
			}
		}
		if (Peices[l]->Type != "King" && Peices[l]->Colour == "WHITE")
		{
			for (int i = 0; i < Peices[l]->AvailableMoves.size(); i++)
			{
				if (Peices[l]->AvailableMoves[i] == KingBPos)
				{
					Peices[l]->GetAvalibleMoves();
					CheckVariblesMain.CheckMoves = Peices[l]->AvailableMoves;
					// Black is in check
					CheckVariblesMain.IsInCheck = true;
				}
			}
		}
	}
	return CheckVariblesMain;

}

void CreateGame::RemoveDeadPiece()
{
	std::vector<int> PosDel;
	for (int i = 0; i < Peices.size(); i++)
	{
		if (Peices[i]->IsDead)
		{
			PosDel.push_back(i);
		}
	}
	for (int l = 0; l < PosDel.size(); l++) {
		Peices.erase(Peices.begin() + PosDel[l]);
		for (int j = 0; j < PosDel.size(); j++)
		{
			PosDel[j] -= 1;
		}
	}
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

