#pragma once
#include "vendor/glm/glm.hpp"
#include "globals.cpp"
#include <vector>
#include "RenderItem.h"
#include <Windows.h>
#include <cmath>
#include "Peices/Pieces.h"

class Rook : public virtual Peices
{
public:
	Rook(glm::vec2 Location, std::string colour);

	std::vector<glm::vec2> GetAvalibleMoves() override;
};

class Pawn : public virtual Peices
{
public:
	Pawn(glm::vec2 Location, std::string colour);

	std::vector<glm::vec2> GetAvalibleMoves() override;
};

class Bishop : public virtual Peices
{
public:
	Bishop(glm::vec2 Location, std::string colour);

	std::vector<glm::vec2> GetAvalibleMoves() override;
};

class Queen : public virtual Peices
{
public:
	Queen(glm::vec2 Location, std::string colour);

	std::vector<glm::vec2> GetAvalibleMoves() override;
};

class Knight : public virtual Peices
{
public:
	Knight(glm::vec2 Location, std::string colour);

	std::vector<glm::vec2> GetAvalibleMoves() override;
};

class King : public virtual Peices
{
public:
	King(glm::vec2 Location, std::string colour);

	std::vector<glm::vec2> GetAvalibleMoves() override;
};