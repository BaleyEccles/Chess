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
		Pieces.push_back(Pawns[i]);
	}
	
	Rook* Rook1 = new Rook(glm::vec2(7.0f, 7.0f), "BLACK");
	Pieces.push_back(Rook1);
	Rook* Rook2 = new Rook(glm::vec2(0.0f, 7.0f), "BLACK");
	Pieces.push_back(Rook2);

	Rook* Rook3 = new Rook(glm::vec2(7.0f, 0.0f), "WHITE");
	Pieces.push_back(Rook3);
	Rook* Rook4 = new Rook(glm::vec2(0.0f, 0.0f), "WHITE");
	Pieces.push_back(Rook4);

	Queen* Queen1 = new Queen(glm::vec2(4.0f, 0.0f), "WHITE");
	Pieces.push_back(Queen1);
	Queen* Queen2 = new Queen(glm::vec2(4.0f, 7.0f), "BLACK");
	Pieces.push_back(Queen2);

	Bishop* Bishop1 = new Bishop(glm::vec2(2.0f, 0.0f), "WHITE");
	Pieces.push_back(Bishop1);
	Bishop* Bishop2 = new Bishop(glm::vec2(5.0f, 0.0f), "WHITE");
	Pieces.push_back(Bishop2);

	Bishop* Bishop3 = new Bishop(glm::vec2(2.0f, 7.0f), "BLACK");
	Pieces.push_back(Bishop3);
	Bishop* Bishop4 = new Bishop(glm::vec2(5.0f, 7.0f), "BLACK");
	Pieces.push_back(Bishop4);

	Knight* Knight1 = new Knight(glm::vec2(1.0f, 0.0f), "WHITE");
	Pieces.push_back(Knight1);
	Knight* Knight2 = new Knight(glm::vec2(6.0f, 0.0f), "WHITE");
	Pieces.push_back(Knight2);

	Knight* Knight3 = new Knight(glm::vec2(1.0f, 7.0f), "BLACK");
	Pieces.push_back(Knight3);
	Knight* Knight4 = new Knight(glm::vec2(6.0f, 7.0f), "BLACK");
	Pieces.push_back(Knight4);
	
	King* King1 = new King(glm::vec2(3.0f, 0.0f), "WHITE");
	Pieces.push_back(King1);

	King* King2 = new King(glm::vec2(3.0f, 7.0f), "BLACK");
	Pieces.push_back(King2);
	DefaultStart = Pieces;
}

void CreateGame::LoadData(std::vector<Peices*> Data)
{
	Pieces = Data;
	
}


void CreateGame::Main()
{
	//LoadData();
	RemoveDeadPiece();
	for (int i = 0; i < Pieces.size(); i++)
	{
		if (CurrentMove == Pieces[i]->Colour)
		{
			Pieces[i]->CanGo = true;
		}
		else
		{
			Pieces[i]->CanGo = false;
		}

		CheckVaribles CheckVaribles = CheckIfInCheck();

		if (CheckVaribles.IsInCheck)
		{
			for (int b = 0; b < Pieces.size(); b++)
			{
				if (Pieces[b]->Type != "King" && Pieces[b]->Colour == CurrentMove)
				{
					for (int u = 0; u < Pieces[b]->AvailableMoves.size(); u++)
					{
						bool CanGo = false;
						
						for (int g = 0; g < CheckVaribles.CheckMoves.size(); g++)
						{
							if (Pieces[b]->AvailableMoves[u] == CheckVaribles.CheckMoves[g])
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
						Pieces[b]->CanGo = CanGo;

					}

				}

				for (int b = 0; b < Pieces.size(); b++)
				{
					std::vector<int> PosDel;

					if (Pieces[b]->Type != "King" && Pieces[b]->Colour == CurrentMove && Pieces[b]->CanGo == true)
					{
						for (int g = 0; g < CheckVaribles.CheckMoves.size(); g++)
						{
							for (int u = 0; u < Pieces[b]->AvailableMoves.size(); u++)
							{
								if (CheckVaribles.CheckMoves[g] != Pieces[b]->AvailableMoves[u])
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
						Pieces[b]->AvailableMoves.erase(Pieces[b]->AvailableMoves.begin() + PosDel[z]);

						for (int j = 0; j < PosDel.size(); j++)
						{

							PosDel[j] -= 1;
						}
					}
					PosDel.clear();
				}
			}
		}
		for (int b = 0; b < Pieces.size(); b++)
		{
			if (Pieces[b]->Type == "King" && Pieces[b]->Colour == CurrentMove)
			{
				std::vector<int> PosDel;

				for (int p = 0; p < Pieces[b]->AvailableMoves.size(); p++)
				{
					for (int a = 0; a < Pieces.size(); a++)
					{
						if (Pieces[a]->Colour != CurrentMove)
						{
							if (Pieces[b] != Pieces[a])
							{
								for (int k = 0; k < Pieces[a]->AvailableMoves.size(); k++)
								{
									if (Pieces[a]->AvailableMoves[k] == Pieces[b]->AvailableMoves[p])
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
					Pieces[b]->AvailableMoves.erase(Pieces[b]->AvailableMoves.begin() + PosDel[z]);

					for (int j = 0; j < PosDel.size(); j++)
					{

						PosDel[j] -= 1;
					}
				}
				PosDel.clear();

			}
		}
		
		Pieces[i]->Main(Pieces);

		if (Pieces[i]->HasMoved == true)
		{
			

			//std::cout << i << std::endl;
			for (int k = 0; k < Pieces.size(); k++)
			{
				Pieces[k]->UpdateAvailableMoves();
			}
			SwapSide();
		}
		Pieces[i]->HasMoved = false;
	}
	RestartGame();

}

CheckVaribles CreateGame::CheckIfInCheck()
{
	CheckVaribles CheckVariblesMain;

	glm::vec2 KingWPos;
	glm::vec2 KingBPos;
	for (int k = 0; k < Pieces.size(); k++)
	{
		if (Pieces[k]->Type == "King")
		{
			if (Pieces[k]->Colour == "BLACK")
			{
				KingBPos = Pieces[k]->Game_Pos;
			}
			if (Pieces[k]->Colour == "WHITE")
			{
				KingWPos = Pieces[k]->Game_Pos;
			}
		}
	}
	for (int l = 0; l < Pieces.size(); l++)
	{
		if (Pieces[l]->Type != "King" && Pieces[l]->Colour == "BLACK")
		{
			for (int i = 0; i < Pieces[l]->AvailableMoves.size(); i++)
			{
				if (Pieces[l]->AvailableMoves[i] == KingWPos)
				{
					Pieces[l]->GetAvalibleMoves();
					CheckVariblesMain.CheckMoves = Pieces[l]->AvailableMoves;

					// White is in check
					CheckVariblesMain.IsInCheck = true;
				}
			}
		}
		if (Pieces[l]->Type != "King" && Pieces[l]->Colour == "WHITE")
		{
			for (int i = 0; i < Pieces[l]->AvailableMoves.size(); i++)
			{
				if (Pieces[l]->AvailableMoves[i] == KingBPos)
				{
					Pieces[l]->GetAvalibleMoves();
					CheckVariblesMain.CheckMoves = Pieces[l]->AvailableMoves;
					// Black is in check
					CheckVariblesMain.IsInCheck = true;
				}
			}
		}
	}
	return CheckVariblesMain;

}

void CreateGame::RestartGame()
{
	if (GetKeyState('R') < 0)
	{
		// massive memory leak, cant delete the data in the vector
		Pieces.clear();
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
			Pieces.push_back(Pawns[i]);
		}

		Rook* Rook1 = new Rook(glm::vec2(7.0f, 7.0f), "BLACK");
		Pieces.push_back(Rook1);
		Rook* Rook2 = new Rook(glm::vec2(0.0f, 7.0f), "BLACK");
		Pieces.push_back(Rook2);

		Rook* Rook3 = new Rook(glm::vec2(7.0f, 0.0f), "WHITE");
		Pieces.push_back(Rook3);
		Rook* Rook4 = new Rook(glm::vec2(0.0f, 0.0f), "WHITE");
		Pieces.push_back(Rook4);

		Queen* Queen1 = new Queen(glm::vec2(4.0f, 0.0f), "WHITE");
		Pieces.push_back(Queen1);
		Queen* Queen2 = new Queen(glm::vec2(4.0f, 7.0f), "BLACK");
		Pieces.push_back(Queen2);

		Bishop* Bishop1 = new Bishop(glm::vec2(2.0f, 0.0f), "WHITE");
		Pieces.push_back(Bishop1);
		Bishop* Bishop2 = new Bishop(glm::vec2(5.0f, 0.0f), "WHITE");
		Pieces.push_back(Bishop2);

		Bishop* Bishop3 = new Bishop(glm::vec2(2.0f, 7.0f), "BLACK");
		Pieces.push_back(Bishop3);
		Bishop* Bishop4 = new Bishop(glm::vec2(5.0f, 7.0f), "BLACK");
		Pieces.push_back(Bishop4);

		Knight* Knight1 = new Knight(glm::vec2(1.0f, 0.0f), "WHITE");
		Pieces.push_back(Knight1);
		Knight* Knight2 = new Knight(glm::vec2(6.0f, 0.0f), "WHITE");
		Pieces.push_back(Knight2);

		Knight* Knight3 = new Knight(glm::vec2(1.0f, 7.0f), "BLACK");
		Pieces.push_back(Knight3);
		Knight* Knight4 = new Knight(glm::vec2(6.0f, 7.0f), "BLACK");
		Pieces.push_back(Knight4);

		King* King1 = new King(glm::vec2(3.0f, 0.0f), "WHITE");
		Pieces.push_back(King1);

		King* King2 = new King(glm::vec2(3.0f, 7.0f), "BLACK");
		Pieces.push_back(King2);
		CurrentMove = "WHITE";
 	}
}

void CreateGame::RemoveDeadPiece()
{
	std::vector<int> PosDel;
	for (int i = 0; i < Pieces.size(); i++)
	{
		if (Pieces[i]->IsDead)
		{
			PosDel.push_back(i);
		}
	}
	for (int l = 0; l < PosDel.size(); l++) {
		Pieces.erase(Pieces.begin() + PosDel[l]);
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

