#include "Pixa/Graphics/VAO.hpp"

#include "Pixa/Core/Engine.hpp"

#include <glad/gl.h>

namespace Pixa
{
    VAO::VAO()
    {
        glGenVertexArrays(1, &mID);
    }

    VAO::~VAO()
    {
        glDeleteVertexArrays(1, &mID);
        mID = 0;
    }

    void VAO::Bind() const
    {
        glBindVertexArray(mID);
        if (mIBO) mIBO->Bind();
    }

    void VAO::Unbind() const
    {
        if (mIBO) mIBO->Unbind();
        glBindVertexArray(0);
    }

    void VAO::AddVertexBuffer(std::shared_ptr<VBO> vbo, const std::vector<u32>& layout)
    {
        if (vbo->GetID () == 0)
        {
            PIXA_WARN("The VBO has an invalid ID");
            return;
        }

        u32 stride = 0;
        for (u32 i : layout) stride += i;
        stride *= sizeof(f32);

        Bind();

        u32 offset = 0;
        for (u32 element : layout)
        {
            glEnableVertexAttribArray(mIndex);
            glVertexAttribPointer(mIndex, element, GL_FLOAT, GL_FALSE, stride, (void*)(size)offset);
            offset += sizeof(f32) * element;
            mIndex++;
        }
        
        mVBOs.push_back(vbo);
    }
    
    void VAO::SetIndexBuffer(std::shared_ptr<IBO> ibo)
    {
        if (ibo->GetID() != 0)
            mIBO = ibo;
    }

    std::shared_ptr<VAO> VAO::Create()
    {
        std::shared_ptr<VAO> vao(new VAO());
        if (!*vao) return nullptr;
        return vao;
    }
}