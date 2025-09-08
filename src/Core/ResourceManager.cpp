#include "Pixa/pch.hpp"

#include "Pixa/Core/ResourceManager.hpp"
#include "Pixa/Core/Engine.hpp"

#include "Pixa/Graphics/Texture.hpp"
#include "Pixa/Graphics/Shader.hpp"

namespace Pixa
{
    ResourceManager::ResourceManager()
    {}

    ResourceManager::~ResourceManager()
    {}

    std::shared_ptr<Texture> ResourceManager::LoadTexture(const str& name, const std::filesystem::path& path)
    {
        std::shared_ptr<Texture> texture = Texture::Create(path);
        if (!*texture)
        {
            PIXA_WARN("Texture {} was not loaded.", path.string().c_str());
            texture = nullptr;
        }

        mTextures[name] = texture;

        return texture;
    }

    std::shared_ptr<Shader> ResourceManager::LoadShader(const str& name, const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath)
    {
        std::shared_ptr<Shader> shader = Shader::Create(vertexPath, fragmentPath);
        if (!*shader)
        {
            PIXA_WARN("Shader [{}, {}] was not loaded.", vertexPath.string().c_str(), fragmentPath.string().c_str());
            shader = nullptr;
        }

        mShaders[name] = shader;

        return shader;
    }

    std::shared_ptr<Texture> ResourceManager::GetTexture(const str& name)
    {
        if (mTextures.find(name) == mTextures.end())
        {
            PIXA_WARN("Could not find texture {}", name);
            return nullptr;
        }

        return mTextures[name];
    }

    std::shared_ptr<Shader> ResourceManager::GetShader(const str& name)
    {
        if (mShaders.find(name) == mShaders.end())
        {
            PIXA_WARN("Could not find shader {}", name);
            return nullptr;
        }

        return mShaders[name];
    }
}