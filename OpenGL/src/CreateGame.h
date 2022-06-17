
#pragma once
#include "vendor/glm/glm.hpp"
#include "globals.cpp"
#include <vector>
#include "RenderItem.h"
#include <Windows.h>
#include <cmath>
#include "Peices/PeicesMain.h"

class CreateGame
{
public:

	CreateGame();


	std::vector<Peices*> Peices;

	void Main();

private:



};