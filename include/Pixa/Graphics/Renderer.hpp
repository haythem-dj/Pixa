#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Core/Window.hpp"

#include <glm/glm.hpp>

#include <memory>

namespace Pixa
{
    class Shader;
    class VAO;
    class VBO;
    class IBO;
    class Texture;

    class MaterialComponent;
    
    class PIXA_API Renderer
    {
    public:
        Renderer(const Window& window);
        ~Renderer();

        void Resize(u32 width, u32 height);

        void BeginRender();
        void EndRender();

        void BeginBatch(std::shared_ptr<Shader> shader);
        void EndBatch();

        void Flush();

        void SetClearColor(const glm::vec4& color);
        void Clear();

        void DrawIndexed(const std::shared_ptr<VAO>& vao,
            const std::shared_ptr<Shader>& shader);
            
    private:
        const Window& mWindow;

        std::shared_ptr<Shader> mActiveShader;

    };
}