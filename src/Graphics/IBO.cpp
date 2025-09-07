#include "Pixa/Graphics/IBO.hpp"

#include <glad/gl.h>

namespace Pixa
{
    IBO::IBO(u32 count, u32* data)
        :mCount(count)
    {
        glGenBuffers(1, &mID);
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(u32), data, GL_STATIC_DRAW);
    }

    IBO::~IBO()
    {
        glDeleteBuffers(1, &mID);
        mID = 0;
    }

    void IBO::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mID);
    }

    void IBO::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    std::shared_ptr<IBO> IBO::Create(u32 count, u32* data)
    {
        std::shared_ptr<IBO> ibo(new IBO(count, data));
        if (!*ibo) return nullptr;
        return ibo;
    }
}