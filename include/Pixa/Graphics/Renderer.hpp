#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Core/Window.hpp"

#include <glm/glm.hpp>

#include <memory>

namespace Pixa
{
    class PIXA_API Renderer
    {
    public:
        Renderer(const Window& window);
        ~Renderer();

        void RenderBegin();
        void RenderEnd();

        void SetClearColor(const glm::vec4& color);
        void Clear();

    private:
        const Window& mWindow;

    };
}