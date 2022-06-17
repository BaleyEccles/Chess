#include "CreateGame.h"

CreateGame::CreateGame()
{
	std::vector<Pawn*> Pawns;
	for (int i = 0; i < 16; ++i) 
	{
		if (i <= 8)
		{
			Pawns.push_back(new Pawn(glm::vec2((float)i, 1.0f), "WHITE"));
		}
		else
		{
			Pawns.push_back(new Pawn(glm::vec2((float)i - 9.0f, 6.0f), "BLACK"));
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

	Knight* Knight1 = new Knight(glm::vec2(2.0f, 4.0f), "WHITE");
	Peices.push_back(Knight1);
	Knight* Knight1 = new Knight(glm::vec2(2.0f, 4.0f), "WHITE");
	Peices.push_back(Knight1);

	Peices.push_back(Knight1);
	King* King1 = new King(glm::vec2(2.0f, 4.0f), "WHITE");
	Peices.push_back(King1);
}

void CreateGame::Main()
{
	for (int i = 0; i < Peices.size(); i++)
	{
		Peices[i]->Main(Peices);
	}
}
