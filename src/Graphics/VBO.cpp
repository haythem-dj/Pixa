#include "Pixa/Graphics/VBO.hpp"

#include "Pixa/Core/Engine.hpp"

#include <glad/gl.h>

namespace Pixa
{
    VBO::VBO(u32 size, f32* data)
    {
        glGenBuffers(1, &mID);
        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    VBO::~VBO()
    {
        glDeleteBuffers(1, &mID);
        mID = 0;
    }

    void VBO::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, mID);
    }

    void VBO::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    std::shared_ptr<VBO> VBO::Create(u32 size, f32* data)
    {
        std::shared_ptr<VBO> vbo(new VBO(size, data));
        if (!*vbo) return nullptr;
        return vbo;
    }
}