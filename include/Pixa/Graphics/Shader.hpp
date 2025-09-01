#pragma once

#include "Pixa/Common/Defines.hpp"

#include <filesystem>
#include <memory>

namespace Pixa
{
    class PIXA_API Shader
    {
    public:
        ~Shader();
    
        explicit operator bool() const { return mID != 0; }

        void Bind() const;
        void Unbind() const;

        u32 GetID() const { return mID; }

        static std::shared_ptr<Shader> Create(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);

    private:
        Shader(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);
        u32 CompileShader(u32 type, const char* source);
        str LoadShader(const std::filesystem::path& path);

    private:
        u32 mID = 0;
    };
}