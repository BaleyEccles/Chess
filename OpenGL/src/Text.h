#include <ft2build.h>
#include FT_FREETYPE_H
#include <iostream>
#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "vendor/glm/glm.hpp"
#include "Shader.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Character {
    unsigned int TextureID;  // ID handle of the glyph texture
    glm::ivec2   Size;       // Size of glyph
    glm::ivec2   Bearing;    // Offset from baseline to left/top of glyph
    unsigned int Advance;    // Offset to advance to next glyph
};

class text
{
public:
	text();

    void RenderText(std::string text, float x, float y, float scale, glm::vec3 color);
    std::map<char, Character> Characters;
    unsigned int VAO, VBO;
    std::unique_ptr<Shader> m_shader;

};