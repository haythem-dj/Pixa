#pragma once

#include "Pixa/Common/Defines.hpp"

#include <memory>
#include <unordered_map>
#include <filesystem>

namespace Pixa
{
    class Texture;
    class Shader;

    class PIXA_API ResourceManager
    {
    public:
        ResourceManager();
        ~ResourceManager();

        std::shared_ptr<Texture> LoadTexture(const str& name, const std::filesystem::path& path);
        std::shared_ptr<Shader> LoadShader(const str& name, const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);

        std::shared_ptr<Texture> GetTexture(const str& name);
        std::shared_ptr<Shader> GetShader(const str& name);
    
    private:
        std::unordered_map<str, std::shared_ptr<Texture>> mTextures;
        std::unordered_map<str, std::shared_ptr<Shader>> mShaders;
    
    };
}