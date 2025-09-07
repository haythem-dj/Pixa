#pragma once

#include "Pixa/Common/Defines.hpp"

#include <filesystem>
#include <memory>
#include <glm/glm.hpp>

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

        void SetInt(const str& name, i32 value);

        void SetFloat(const str& name, f32 value);
        void SetFloat2(const str& name, const glm::vec2& value);
        void SetFloat3(const str& name, const glm::vec3& value);
        void SetFloat4(const str& name, const glm::vec4& value);

        void SetMatrix3(const str& name, const glm::mat3& value);
        void SetMatrix4(const str& name, const glm::mat4& value);

    private:
        Shader(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);
        u32 CompileShader(u32 type, const char* source);
        str LoadShader(const std::filesystem::path& path);

    private:
        u32 mID = 0;
    };
}