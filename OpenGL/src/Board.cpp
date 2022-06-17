#include "Board.h"

Board::Board(glm::vec4 Colour1, glm::vec4 Colour2)
	:BoardRender("res/shaders/Board.shader")
{
    ColourA = Colour1;
    ColourB = Colour2;

	int count = 0;
    float colourR, colourG, colourB, colourA;
    std::vector<std::vector<float>> CubeData(64);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j % 2 == 0)
            {
                if (i % 2 == 0)
                {
                    colourR = ColourA.x;
                    colourG = ColourA.y;
                    colourB = ColourA.z;
                    colourA = ColourA.w;
                }
                else {
                    colourR = ColourB.x;
                    colourG = ColourB.y;
                    colourB = ColourB.z;
                    colourA = ColourB.w;
                }
            }
            else
            {
                if (i % 2 == 0)
                {
                    colourR = ColourB.x;
                    colourG = ColourB.y;
                    colourB = ColourB.z;
                    colourA = ColourB.w;
                }
                else {
                    colourR = ColourA.x;
                    colourG = ColourA.y;
                    colourB = ColourA.z;
                    colourA = ColourA.w;
                }

            }
            std::vector<float> k = {
                +XCoordData, -YCoordData, colourR, colourG, colourB, colourA,
                +XCoordData, +YCoordData, colourR, colourG, colourB, colourA,
                -XCoordData, +YCoordData, colourR, colourG, colourB, colourA,
                -XCoordData, -YCoordData, colourR, colourG, colourB, colourA
            };
            CubeData[count] = k;
            count += 1;
        }
    }

    std::vector<unsigned int> Floats = { 2, 4 };
    for (int k = 0; k < CubeData.size(); k++)
    {
        BoardRender.AddData(CubeData[k], Floats);
    }

}

void Board::RenderBoard()
{
    BoardRender.Render();
}
