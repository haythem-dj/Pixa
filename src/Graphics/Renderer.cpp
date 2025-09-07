#include "Pixa/pch.hpp"

#include "Pixa/Graphics/Renderer.hpp"
#include "Pixa/Graphics/Shader.hpp"
#include "Pixa/Graphics/VAO.hpp"
#include "Pixa/Graphics/Texture.hpp"

#include "Pixa/Core/Engine.hpp"

#include <glad/gl.h>

namespace Pixa
{
    Renderer::Renderer(const Window& window)
        :mWindow(window)
    {
    }

    Renderer::~Renderer()
    {}

    void Renderer::RenderBegin() const
    {}

    void Renderer::RenderEnd() const
    {
        mWindow.SwapBuffers();
    }

    void Renderer::SetClearColor(const glm::vec4& color) const
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void Renderer::Clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::DrawIndexed(const std::shared_ptr<VAO>& vao, const std::shared_ptr<Shader>& shader) const
    {
        shader->Bind();
        vao->Bind();
        glDrawElements(GL_TRIANGLES, vao->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);
    }

    void Renderer::DrawTextured(const std::shared_ptr<VAO>& vao,
            const std::shared_ptr<Shader>& shader,
            const std::shared_ptr<Texture>& texture) const
    {
        texture->Bind();
        DrawIndexed(vao, shader);
    }
}