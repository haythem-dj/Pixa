#pragma once

#include "Pixa/Common/Defines.hpp"

#include <memory>
#include <vector>
#include <glm/glm.hpp>

namespace Pixa
{
    struct PIXA_API Vertex
    {
        glm::vec2 Position{0.0f};
        glm::vec2 TexCoords{0.0f};
        glm::vec4 Color{1.0f};
    };
    
    class PIXA_API Mesh
    {
        public:
            ~Mesh();

            explicit operator bool() const { return mVAO != 0 && mIBO != 0; }

            void Bind() const;
            void Unbind() const;

            u32 GetIndexCount() const { return mIndexCount; }

            static std::shared_ptr<Mesh> Create(const std::vector<Vertex>& vertices, const std::vector<u32>& indices);
        
        private:
            Mesh(const std::vector<Vertex>& vertices, const std::vector<u32>& indices);

        private:
            u32 mVAO = 0;
            u32 mIBO = 0;

            u32 mIndexCount = 0;
        
    };
}