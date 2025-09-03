#include "Pixa/pch.hpp"

#include "Pixa/Graphics/Texture.hpp"

#include "Pixa/Core/Engine.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>
#include <glad/gl.h>

namespace Pixa
{
    Texture::Texture(const std::filesystem::path& texturePath)
    {
        glGenTextures(1, &mID);
        Bind();

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

        stbi_set_flip_vertically_on_load(true);
        i32 width, height, channels;
        u8* data = stbi_load(texturePath.string().c_str(), &width, &height, &channels, 0);

        if (!data)
        {
            PIXA_ERROR("Could not load texture {}", texturePath.string().c_str());
            mID = 0;
            return;
        }

        u32 internalFormat = 0;
        u32 dataFormat = 0;

        if (channels == 3)
        {
            internalFormat = GL_RGB8;
            dataFormat = GL_RGB;
        }
        else if (channels == 4)
        {
            internalFormat = GL_RGBA8;
            dataFormat = GL_RGBA;
        }
        else
        {
            PIXA_ERROR("unsipported image format for texture {}", texturePath.string().c_str());
            mID = 0;
            return;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }

    Texture::~Texture()
    {
        glDeleteTextures(1, &mID);
        mID = 0;
    }

    void Texture::Bind(u32 slot) const
    {
        glActiveTexture(slot);
        glBindTexture(GL_TEXTURE_2D, mID);
    }

    void Texture::Unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    std::shared_ptr<Texture> Texture::Create(const std::filesystem::path& texturePath)
    {
        std::shared_ptr<Texture> texture(new Texture(texturePath));
        if (!*texture) return nullptr;
        return texture;
    }
}