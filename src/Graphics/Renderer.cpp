#include "Pixa/pch.hpp"

#include "Pixa/Graphics/Renderer.hpp"
#include "Pixa/Graphics/Shader.hpp"
#include "Pixa/Graphics/VAO.hpp"
#include "Pixa/Graphics/VBO.hpp"
#include "Pixa/Graphics/IBO.hpp"
#include "Pixa/Graphics/Texture.hpp"

#include "Pixa/Core/Engine.hpp"

#include "Pixa/Scene/Camera.hpp"

#include "Pixa/Scene/Components/MaterialComponent.hpp"

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

    void Renderer::BeginRender()
    {}

    void Renderer::EndRender()
    {
        mWindow.SwapBuffers();
    }

    void Renderer::BeginBatch(std::shared_ptr<Shader> shader)
    {
        mActiveShader = shader;
        
        shader->Bind();
    }

    void Renderer::EndBatch()
    {
    }

    void Renderer::Flush()
    {}

    void Renderer::SetClearColor(const glm::vec4& color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void Renderer::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::DrawIndexed(const std::shared_ptr<VAO>& vao, const std::shared_ptr<Shader>& shader)
    {
        shader->Bind();
        vao->Bind();
        glDrawElements(GL_TRIANGLES, vao->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);
    }

}