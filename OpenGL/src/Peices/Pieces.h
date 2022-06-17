#include "vendor/glm/glm.hpp"
#include "globals.cpp"
#include <vector>
#include "RenderItem.h"
#include <Windows.h>
#include <cmath>

class Peices
{
public:
	Peices(glm::vec2 Location, std::string colour, std::string PeiceType);

	glm::vec2 position;

	glm::vec2 Game_Pos;

	glm::vec2 position_screen;

	std::string Colour;

	bool IsDead = false;

	virtual bool IsOutOfBoard(glm::vec2 Pos);

	virtual void GetMousePos();

	virtual void GetPosScreen();

	virtual bool CheckMouseCollison();

	virtual void SetPosToMouse();

	virtual void Main(std::vector<Peices*> PeiceVec);

	virtual void Location();

	virtual void Render();

	virtual void SetPosToCell();

	virtual bool CheckMove(glm::vec2 Pos);

	virtual void CheckTakePeice();

	virtual std::vector<glm::vec2> GetAvalibleMoves();

	virtual std::vector<glm::vec2> RemoveSamePeice(std::vector<glm::vec2> Moves);

	std::vector<Peices*> PeiceVecMain;

	RenderItem Peice;

	HWND hwnd;

	POINT MousePos;
};
