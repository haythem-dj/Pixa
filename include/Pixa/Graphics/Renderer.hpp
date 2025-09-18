#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Core/Window.hpp"

#include <glm/glm.hpp>

#include <memory>

namespace Pixa
{
    class Shader;
    class Mesh;
    class Texture;
    
    class PIXA_API Renderer
    {
    public:
        Renderer(const Window& window);
        ~Renderer();

        void Resize(u32 width, u32 height);

        void RenderBegin() const;
        void RenderEnd() const;

        void SceneBegin(const std::shared_ptr<Shader>& shader) const;
        void SceneEnd() const;

        void SetClearColor(const glm::vec4& color) const;
        void Clear() const;

        void DrawIndexed(const std::shared_ptr<Mesh>& mesh,
            const std::shared_ptr<Shader>& shader) const;
            
        void DrawTextured(const std::shared_ptr<Mesh>& mesh,
            const std::shared_ptr<Shader>& shader,
            const std::shared_ptr<Texture>& texture) const;

    private:
        const Window& mWindow;

    };
}