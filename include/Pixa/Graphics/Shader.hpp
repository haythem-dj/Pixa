#pragma once

#include "Pixa/Common/Defines.hpp"

#include <filesystem>

namespace Pixa
{
    class PIXA_API Shader
    {
    public:
        Shader(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);
        ~Shader();

        explicit operator bool() const { return mID != 0; }

        void Bind() const;
        void Unbind() const;

    private:
        u32 CompileShader(u32 type, const char* source);
        str LoadShader(const std::filesystem::path& path);

    private:
        u32 mID = 0;
    };
}