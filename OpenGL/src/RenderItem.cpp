#include "RenderItem.h"

RenderItem::RenderItem(std::string ShaderLoc, std::string TextureLoc)
{

    m_shader = std::make_unique<Shader>(ShaderLoc);
    m_VAO = std::make_unique<VertexArray>();
    Shader shader();
    m_shader->Bind();

    for (int i = 0; i < m_VetexBufferSize / 6; i++) {
        m_indices[0 + i * 6] = (i * 4);
        m_indices[1 + i * 6] = (i * 4) + 1;
        m_indices[2 + i * 6] = (i * 4) + 2;
        m_indices[3 + i * 6] = (i * 4) + 2;
        m_indices[4 + i * 6] = (i * 4) + 3;
        m_indices[5 + i * 6] = (i * 4);
    }
    tex = TextureLoc;
    m_IndexBuffer = std::make_unique<IndexBuffer>(m_indices, sizeof(m_indices) / sizeof(m_indices[0]));
    m_shader->SetUniform1i("u_Texture", 0);
    m_Texture = std::make_unique<Texture>(TextureLoc);
    m_shader->SetUniform1i("u_Texture", 0);

}

RenderItem::~RenderItem()
{
}

void RenderItem::Render(float Pos1, float Pos2)
{
    Renderer renderer;
    //std::cout << tex << std::endl;
    //m_shader->SetUniform2f("u_pos", -7*(Windowx / 8.0f) / Windowx, -7* (Windowy / 8.0f) / Windowy);

    m_Texture->Bind();
    m_shader->Bind();
    m_shader->SetUniform2f("u_screensize", Windowx, Windowy);
    if (Pos1 != -1 || Pos2 != -1)
    {
        m_shader->SetUniform2f("u_Pos", Pos1, Pos2);
    }
    renderer.Draw(*m_VAO, *m_IndexBuffer, *m_shader);
    m_Texture->Unbind();
}

void RenderItem::AddData(std::vector<float> Data, std::vector<unsigned int> NumberOfFloats)
{
    VertexBufferLayout m_layout_Batch;

    for (int i = 0; i < NumberOfFloats.size(); i++)
    {
        m_layout_Batch.AddFloat(NumberOfFloats[i]);
    }

    for (int i = 0; i < Data.size(); i++)
    {
        m_VertexData[m_k] = Data[i];
        m_k += 1;
    }
    m_VertexBuffer = std::make_unique<VertexBuffer>(m_VertexData, m_VetexBufferSize * sizeof(float));
    m_VAO->AddBuffer(*m_VertexBuffer, m_layout_Batch);
}
