#include "Renderer.h"
#include <iostream>

void Renderer::Clear() const
{
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::DrawText(const VertexArray& va, const Shader& shader) const
{
    shader.Bind();
    va.Bind();
    glDrawArrays(GL_TRIANGLES, 0, 6);
}
