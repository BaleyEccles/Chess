#include "CreateGame.h"

CreateGame::CreateGame()
	:TextMain()
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

void CreateGame::DealWithCheck(CheckVaribles CheckVar)
{
	std::vector<glm::vec2> AvailibleMoves;
	bool ShouldCheckLoc = true;
	if (CheckVar.CheckPieceType != "Knight")
	{
		
		glm::vec2 PeiceRelTo00 = CheckVar.KingPos - CheckVar.CheckPiecePos;
		if (PeiceRelTo00.x == 0.0f && PeiceRelTo00.y < 0.0f)
		{// is down
			for (int h = 0; h < 20; h++)
			{
				if (ShouldCheckLoc)
				{
					AvailibleMoves.push_back(glm::vec2(CheckVar.KingPos.x, CheckVar.KingPos.y + (float)h));
					if (glm::vec2(CheckVar.KingPos.x, CheckVar.KingPos.y + (float)h) == CheckVar.CheckPiecePos)
					{
						ShouldCheckLoc = false;
					}
				}
			}
		}
		if (PeiceRelTo00.x == 0.0f && PeiceRelTo00.y > 0.0f)
		{// is up
			for (int h = 0; h < 20; h++)
			{

				if (ShouldCheckLoc)
				{
					AvailibleMoves.push_back(glm::vec2(CheckVar.KingPos.x, CheckVar.KingPos.y - (float)h));
					if (glm::vec2(CheckVar.KingPos.x, CheckVar.KingPos.y - (float)h) == CheckVar.CheckPiecePos)
					{
						ShouldCheckLoc = false;
					}
				}
			}
		}
		if (PeiceRelTo00.x < 0.0f && PeiceRelTo00.y == 0.0f)
		{// is left
			for (int h = 0; h < 20; h++)
			{

				if (ShouldCheckLoc)
				{
					AvailibleMoves.push_back(glm::vec2(CheckVar.KingPos.x + (float)h, CheckVar.KingPos.y));
					if (glm::vec2(CheckVar.KingPos.x + (float)h, CheckVar.KingPos.y) == CheckVar.CheckPiecePos)
					{
						ShouldCheckLoc = false;
					}
				}
			}
		}
		if (PeiceRelTo00.x > 0.0f && PeiceRelTo00.y == 0.0f)
		{// is right

			for (int h = 0; h < 20; h++)
			{

				if (ShouldCheckLoc)
				{
					AvailibleMoves.push_back(glm::vec2(CheckVar.KingPos.x - (float)h, CheckVar.KingPos.y));
					if (glm::vec2(CheckVar.KingPos.x - (float)h, CheckVar.KingPos.y) == CheckVar.CheckPiecePos)
					{
						ShouldCheckLoc = false;
					}
				}
			}
		}

		if (PeiceRelTo00.x > 0.0f && PeiceRelTo00.y > 0.0f)
		{// is up right

			for (int h = 0; h < 20; h++)
			{
				if (ShouldCheckLoc)
				{

					AvailibleMoves.push_back(glm::vec2(CheckVar.KingPos.x - (float)h, CheckVar.KingPos.y - (float)h));
					if (glm::vec2(CheckVar.KingPos.x - (float)h, CheckVar.KingPos.y - (float)h) == CheckVar.CheckPiecePos)
					{
						ShouldCheckLoc = false;
					}
				}
			}
		}
		if (PeiceRelTo00.x > 0.0f && PeiceRelTo00.y < 0.0f)
		{// is down right

			for (int h = 0; h < 20; h++)
			{
				if (ShouldCheckLoc)
				{

					AvailibleMoves.push_back(glm::vec2(CheckVar.KingPos.x - (float)h, CheckVar.KingPos.y + (float)h));
					if (glm::vec2(CheckVar.KingPos.x - (float)h, CheckVar.KingPos.y + (float)h) == CheckVar.CheckPiecePos)
					{
						ShouldCheckLoc = false;
					}
				}
			}
		}
		if (PeiceRelTo00.x < 0.0f && PeiceRelTo00.y < 0.0f)
		{// is down left

			for (int h = 0; h < 20; h++)
			{

				if (ShouldCheckLoc)
				{
					AvailibleMoves.push_back(glm::vec2(CheckVar.KingPos.x + (float)h, CheckVar.KingPos.y + (float)h));
					if (glm::vec2(CheckVar.KingPos.x + (float)h, CheckVar.KingPos.y + (float)h) == CheckVar.CheckPiecePos)
					{
						ShouldCheckLoc = false;
					}
				}
			}
		}
		if (PeiceRelTo00.x < 0.0f && PeiceRelTo00.y > 0.0f)
		{// is up left

			for (int h = 0; h < 20; h++)
			{

				if (ShouldCheckLoc)
				{
					AvailibleMoves.push_back(glm::vec2(CheckVar.KingPos.x + (float)h, CheckVar.KingPos.y - (float)h));
					if (glm::vec2(CheckVar.KingPos.x + (float)h, CheckVar.KingPos.y - (float)h) == CheckVar.CheckPiecePos)
					{
						ShouldCheckLoc = false;
					}
				}
			}
		}
	}
	else {
		AvailibleMoves.push_back(CheckVar.CheckPiecePos);
	}


	for (int v = 0; v < Pieces.size(); v++)
	{
		if (Pieces[v]->Colour != CurrentMove)
		{
			std::vector<bool> LocToRemove(Pieces[v]->AvailableMoves.size());
			std::fill(LocToRemove.begin(), LocToRemove.end(), false);
			for (int l = 0; l < Pieces[v]->AvailableMoves.size(); l++)
			{
				for (int j = 0; j < AvailibleMoves.size(); j++)
				{
					if (Pieces[v]->AvailableMoves[l] == AvailibleMoves[j])
					{
						LocToRemove[l] = true;
					}

				}
			}

			// removes location that the peice cant move to 
			for (int u = 0; u < LocToRemove.size(); u++)
			{
				if (LocToRemove[u] == false && Pieces[v]->Type != "King")
				{
					Pieces[v]->AvailableMoves[u] = glm::vec2(-100.0f, -150.0f);
				}

			}
			if (Pieces[v]->Type == "King")
			{
				Pieces[v]->AvailableMoves.clear();
				Pieces[v]->AvailableMoves.push_back(glm::vec2(Pieces[v]->Game_Pos.x + 1.0f, Pieces[v]->Game_Pos.y + 1.0f));
				Pieces[v]->AvailableMoves.push_back(glm::vec2(Pieces[v]->Game_Pos.x - 1.0f, Pieces[v]->Game_Pos.y - 1.0f));
				Pieces[v]->AvailableMoves.push_back(glm::vec2(Pieces[v]->Game_Pos.x - 1.0f, Pieces[v]->Game_Pos.y + 1.0f));
				Pieces[v]->AvailableMoves.push_back(glm::vec2(Pieces[v]->Game_Pos.x + 1.0f, Pieces[v]->Game_Pos.y - 1.0f));
				Pieces[v]->AvailableMoves.push_back(glm::vec2(Pieces[v]->Game_Pos.x + 1.0f, Pieces[v]->Game_Pos.y));
				Pieces[v]->AvailableMoves.push_back(glm::vec2(Pieces[v]->Game_Pos.x - 1.0f, Pieces[v]->Game_Pos.y));
				Pieces[v]->AvailableMoves.push_back(glm::vec2(Pieces[v]->Game_Pos.x, Pieces[v]->Game_Pos.y + 1.0f));
				Pieces[v]->AvailableMoves.push_back(glm::vec2(Pieces[v]->Game_Pos.x, Pieces[v]->Game_Pos.y - 1.0f));
				Pieces[v]->RemoveSamePeice();
			}
		}
	}

}






void CreateGame::Main()
{
	DeadScreen();

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

		Pieces[i]->Main(Pieces);

		if (Pieces[i]->HasMoved == true)
		{
			//std::cout << i << std::endl;
			for (int k = 0; k < Pieces.size(); k++)
			{
				Pieces[k]->UpdateAvailableMoves();
			}
			CheckVaribles CheckVaribles = CheckIfInCheck();

			if (CheckVaribles.IsInCheck)
			{
				DealWithCheck(CheckVaribles);
				CheckVaribles.IsInCheck = false;
			}
			CheckPromotion();

			MoveNumber += 1;
			//std::cout << MoveNumber << std::endl;
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
	int KingWVecPos;
	int KingBVecPos;
	for (int k = 0; k < Pieces.size(); k++)
	{
		if (Pieces[k]->Type == "King")
		{
			if (Pieces[k]->Colour == "BLACK")
			{
				KingBPos = Pieces[k]->Game_Pos;
				KingBVecPos = k;
			}
			if (Pieces[k]->Colour == "WHITE")
			{
				KingWPos = Pieces[k]->Game_Pos;
				KingWVecPos = k;
			}
		}
	}
	for (int l = 0; l < Pieces.size(); l++)
	{
		if (Pieces[l]->Type != "King" && Pieces[l]->Colour == "BLACK" && Pieces[l]->IsDead == false)
		{
			for (int i = 0; i < Pieces[l]->AvailableMoves.size(); i++)
			{
				if (Pieces[l]->AvailableMoves[i] == KingWPos)
				{
					// White is in check
					CheckVariblesMain.IsInCheck = true;
					CheckVariblesMain.ColourInCheck = "WHITE";

					CheckVariblesMain.KingPos = KingWPos;
					CheckVariblesMain.KingVecPos = KingWVecPos;

					CheckVariblesMain.CheckPiecePos = Pieces[l]->Game_Pos;
					CheckVariblesMain.CheckPieceVecPos = l;
					CheckVariblesMain.CheckPieceType = Pieces[l]->Type;



				}
			}
		}
		if (Pieces[l]->Type != "King" && Pieces[l]->Colour == "WHITE" && Pieces[l]->IsDead == false)
		{
			for (int i = 0; i < Pieces[l]->AvailableMoves.size(); i++)
			{
				if (Pieces[l]->AvailableMoves[i] == KingBPos)
				{
					// Black is in check
					CheckVariblesMain.IsInCheck = true;
					CheckVariblesMain.ColourInCheck = "BLACK";

					CheckVariblesMain.KingPos = KingBPos;
					CheckVariblesMain.KingVecPos = KingBVecPos;

					CheckVariblesMain.CheckPiecePos = Pieces[l]->Game_Pos;
					CheckVariblesMain.CheckPieceVecPos = l;
					CheckVariblesMain.CheckPieceType = Pieces[l]->Type;
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
		Winner.GameIsDone = false;
		// massive memory leak, cant delete the data in the vector
		//for (int b = 0; b < Pieces.size(); b++)
		//{
		//	delete Pieces[b];
		//}
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

void CreateGame::CheckPromotion()
{// promote to queen
	bool CheckPromo = false;
	for (int p = 0; p < Pieces.size(); p++)
	{
		if (Pieces[p]->Type == "Pawn" && (Pieces[p]->Game_Pos.y == 0.0f || Pieces[p]->Game_Pos.y == 7.0f))
		{
			CheckPromo = true;
		}
	}
	if (CheckPromo)
	{
		bool WhitePromo = false;
		bool BlackPromo = false;
		Queen* QueenWhite = new Queen(glm::vec2(-10.0f, -10.0f), "WHITE");
		Queen* QueenBlack = new Queen(glm::vec2(-10.0f, -10.0f), "BLACK");

		for (int l = 0; l < Pieces.size(); l++)
		{
			if (Pieces[l]->Game_Pos.y == 7.0f && Pieces[l]->Colour == "WHITE" && Pieces[l]->Type == "Pawn")
			{ 
				Pieces[l]->IsDead = true;
				QueenWhite->Game_Pos = Pieces[l]->Game_Pos;
				WhitePromo = true;
			}
			if (Pieces[l]->Game_Pos.y == 0.0f && Pieces[l]->Colour == "BLACK" && Pieces[l]->Type == "Pawn")
			{
				Pieces[l]->IsDead = true;
				QueenBlack->Game_Pos = Pieces[l]->Game_Pos;
				BlackPromo = true;
			}
		}
		if (WhitePromo == true)
		{
			Pieces.push_back(QueenWhite);
			CurrentMove = "BLACK";
		}
		if (BlackPromo == true)
		{
			Pieces.push_back(QueenBlack);
			CurrentMove = "WHITE";
		}
		RemoveDeadPiece();
	}
}

void CreateGame::DeadScreen()
{
	int NumberOfKings = 0;
	for (int i = 0; i < Pieces.size(); i++)
	{
		if (Pieces[i]->Type == "King")
		{
			NumberOfKings += 1;
		}
	}
	if (NumberOfKings != 2)
	{
		Winner.GameIsDone = true;
		if (CurrentMove == "BLACK")
		{
			Winner.Text = "The Winner is White";
		}
		if (CurrentMove == "WHITE")
		{
			Winner.Text = "The Winner is Black";
		}
	}

	if (Winner.GameIsDone == true)
	{
		float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		TextMain.RenderText(Winner.Text, 5.0f, 50.0f, 0.2f, glm::vec3(r, g, b));
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