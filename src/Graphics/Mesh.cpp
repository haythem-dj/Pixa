#include "Pixa/pch.hpp"

#include "Pixa/Graphics/Mesh.hpp"

#include <glad/gl.h>

namespace Pixa
{
    Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<u32>& indices)
        :mIndexCount(indices.size())
    {
        u32 vbo;
        glGenVertexArrays(1, &mVAO);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &mIBO);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(u32), indices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

        glBindVertexArray(mVAO);

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(glm::vec2));
        glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec2)+sizeof(glm::vec2)));

        // glDeleteBuffers(1, &vbo);
    }

    Mesh::~Mesh()
    {
        glDeleteVertexArrays(1, &mVAO);
        glDeleteBuffers(1, &mIBO);

        mVAO = 0;
        mIBO = 0;
    }

    void Mesh::Bind() const
    {
        glBindVertexArray(mVAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
    }

    void Mesh::Unbind() const
    {
        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    std::shared_ptr<Mesh> Mesh::Create(const std::vector<Vertex>& vertices, const std::vector<u32>& indices)
    {
        std::shared_ptr<Mesh> mesh(new Mesh(vertices, indices));
        if (!*mesh) return nullptr;
        return mesh;
    }
}