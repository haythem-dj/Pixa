#include "Pixa/pch.hpp"

#include "Pixa/Graphics/Renderer.hpp"
#include "Pixa/Graphics/Shader.hpp"
#include "Pixa/Graphics/Mesh.hpp"
#include "Pixa/Graphics/Texture.hpp"

#include "Pixa/Core/Engine.hpp"

#include "Pixa/Scene/Camera.hpp"

#include <glad/gl.h>

namespace Pixa
{
    Renderer::Renderer(const Window& window)
        :mWindow(window)
    {
    }

    Renderer::~Renderer()
    {}

    void Renderer::Resize(u32 width, u32 height)
    {
        glViewport(0, 0, width, height);
    }

    void Renderer::RenderBegin() const
    {}

    void Renderer::RenderEnd() const
    {
        mWindow.SwapBuffers();
    }

    void Renderer::SceneBegin(const std::shared_ptr<Shader>& shader) const
    {
        shader->Bind();
    }

    void Renderer::SceneEnd() const
    {}

    void Renderer::SetClearColor(const glm::vec4& color) const
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void Renderer::Clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::DrawIndexed(const std::shared_ptr<Mesh>& mesh, const std::shared_ptr<Shader>& shader) const
    {
        shader->Bind();
        mesh->Bind();
        glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, 0);
    }

    void Renderer::DrawTextured(const std::shared_ptr<Mesh>& mesh,
            const std::shared_ptr<Shader>& shader,
            const std::shared_ptr<Texture>& texture) const
    {
        texture->Bind();
        shader->SetInt("uTex", 1);
        DrawIndexed(mesh, shader);
    }
}