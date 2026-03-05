#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Graphics/VBO.hpp"
#include "Pixa/Graphics/IBO.hpp"

#include <memory>
#include <vector>

namespace Pixa
{
    class PIXA_API VAO
    {
    public:
        ~VAO();

        explicit operator bool() const { return mID != 0; }

        void Bind() const;
        void Unbind() const;

        u32 GetID() const { return mID; }

        static std::shared_ptr<VAO> Create();

        void AddVertexBuffer(std::shared_ptr<VBO> vbo, const std::vector<u32>& layout);
        void SetIndexBuffer(std::shared_ptr<IBO> ibo);

        const std::vector<std::shared_ptr<VBO>>& GetVertexBuffers() const { return mVBOs; }
        std::shared_ptr<IBO> GetIndexBuffer() { return mIBO; }
        
    private:
        VAO();

    private:
        u32 mID = 0;

        u32 mIndex = 0;

        std::vector<std::shared_ptr<VBO>> mVBOs;
        std::shared_ptr<IBO> mIBO = nullptr;
    
    };
}