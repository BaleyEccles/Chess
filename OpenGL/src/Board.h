#include "globals.cpp"
#include "RenderItem.h"

class Board
{
public:
	Board(glm::vec4 Colour1, glm::vec4 Colour2);

	void RenderBoard();

private:

	glm::vec4 ColourA;
	glm::vec4 ColourB;

	RenderItem BoardRender;


};
