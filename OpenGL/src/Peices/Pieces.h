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

	bool HasMoved = true; 
	bool IsHeld = false;

	glm::vec2 position;

	glm::vec2 Game_Pos;

	glm::vec2 position_screen;

	std::string Colour;

	std::vector<glm::vec2> AvailableMoves;
	
	bool IsDead = false;


	virtual bool IsOutOfBoard(glm::vec2 Pos);

	virtual void GetMousePos();

	virtual void GetPosScreen();

	virtual bool CheckMouseCollison();

	virtual void SetPosToMouse();

	virtual void Main(std::vector<Peices*> PeiceVec);

	virtual void Location();

	virtual void Render();

	virtual std::vector<glm::vec2> RemoveSamePeice(std::vector<glm::vec2> Moves);

	virtual void SetPosToCell();

	virtual bool CheckMove(glm::vec2 Pos);

	virtual bool CheckPosIsOccupied(glm::vec2 Pos);

	virtual void CheckTakePeice();

	virtual std::vector<glm::vec2> GetAvalibleMoves();


	virtual void UpdateAvailableMoves();


	std::vector<Peices*> PeiceVecMain;

	RenderItem Peice;

	HWND hwnd;

	POINT MousePos;

	bool CanGo = true;
	std::string Type;
	RenderItem CellMove;


};
