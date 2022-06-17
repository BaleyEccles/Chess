#pragma once
#include "Texture.h"

#include <GL/glew.h>
#include "Renderer.h"
#include "Debug.h"
#include "VertexBufferLayout.h"
#include <memory>
#include "VertexBuffer.h"
#include <iostream>
#include <vector>
#include "globals.cpp"

class RenderItem
{
public:
	RenderItem(std::string ShaderLoc, std::string TextureLoc = "");
	~RenderItem();

	void Render(float Pos1 = -1, float Pos2 = -1);

    void AddData(std::vector<float> Data, std::vector<unsigned int> NumberOfFloats);

    const static int m_VetexBufferSize = 10000;
    float m_VertexData[m_VetexBufferSize];
    unsigned int m_indices[m_VetexBufferSize];

private:

    VertexBufferLayout m_layout_Batch;
    std::unique_ptr<VertexArray> m_VAO;
    std::unique_ptr<IndexBuffer> m_IndexBuffer;
    std::unique_ptr<Shader> m_shader;
    std::unique_ptr<VertexBuffer> m_VertexBuffer;
    std::unique_ptr<Texture> m_Texture;
    int m_k = 0;
    std::string tex;
};