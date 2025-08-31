#include "Pixa/pch.hpp"

#include "Pixa/Graphics/Renderer.hpp"

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

    void Renderer::RenderBegin()
    {}

    void Renderer::RenderEnd()
    {
        mWindow.SwapBuffers();
    }

    void Renderer::SetClearColor(const glm::vec4& color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void Renderer::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}