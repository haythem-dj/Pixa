#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Core/Window.hpp"

#include <glm/glm.hpp>

#include <memory>

namespace Pixa
{
    class Shader;
    class VAO;
    
    class PIXA_API Renderer
    {
    public:
        Renderer(const Window& window);
        ~Renderer();

        void RenderBegin();
        void RenderEnd();

        void SetClearColor(const glm::vec4& color) const;
        void Clear() const;

        void DrawIndexed(const std::shared_ptr<VAO>& vao, const std::shared_ptr<Shader>& shader) const;

    private:
        const Window& mWindow;

    };
}