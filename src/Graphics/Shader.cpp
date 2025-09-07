#include "Pixa/pch.hpp"

#include "Pixa/Graphics/Shader.hpp"

#include "Pixa/Core/Engine.hpp"

#include <fstream>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/gl.h>

namespace Pixa
{
    Shader::Shader(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath)
    {
        str vertexSource = LoadShader(vertexPath);
        str fragmentSource = LoadShader(fragmentPath);

        mID = glCreateProgram();

        i32 vertexID = CompileShader(GL_VERTEX_SHADER, vertexSource.c_str());
        i32 fragmentID = CompileShader(GL_FRAGMENT_SHADER, fragmentSource.c_str());

        if (vertexID == -1 || fragmentID == -1)
        {
            PIXA_ERROR("Failed to compile shader");
            mID = 0;
            return;
        }

        glAttachShader(mID, vertexID);
        glAttachShader(mID, fragmentID);

        glLinkProgram(mID);
        glValidateProgram(mID);

        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
    }

    Shader::~Shader()
    {
        glDeleteProgram(mID);
        mID = 0;
    }

    void Shader::Bind() const
    {
        glUseProgram(mID);
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

    u32 Shader::CompileShader(u32 type, const char* source)
    {
        PIXA_ASSERT(type == GL_VERTEX_SHADER || type == GL_FRAGMENT_SHADER, "Shader type is not valid");

        i32 status;
        u32 shader = glCreateShader(type);
        glShaderSource(shader, 1, &source, NULL);
        glCompileShader(shader);
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

        if (status != GL_TRUE)
        {
            i32 length;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
            str err(length, '\0');
            glGetShaderInfoLog(shader, length, &length, err.data());
            PIXA_ERROR("Failed to compile {} shader: {}", type == GL_VERTEX_SHADER? "vertex" : "fragment", err.c_str());
        }

        return shader;
    }

    str Shader::LoadShader(const std::filesystem::path& path)
    {
        std::ifstream shader(path);
        if (!shader.is_open())
        {
            PIXA_ERROR("Can not open file: {}", path.string());
            return std::string();
        }

        str line;
        std::stringstream ss;

        while (getline(shader, line))
        {
            ss << line << "\n";
        }

        shader.close();

        return ss.str();
    }

    std::shared_ptr<Shader> Shader::Create(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath)
    {
        std::shared_ptr<Shader> shader(new Shader(vertexPath, fragmentPath));
        if (!*shader) return nullptr;
        return shader;
    }

    void Shader::SetInt(const str& name, i32 value)
    {
        u32 location = glGetUniformLocation(mID, name.c_str());
        glUniform1i(location, value);
    }

    void Shader::SetFloat(const str& name, f32 value) 
    {
        u32 location = glGetUniformLocation(mID, name.c_str());
        glUniform1f(location, value);
    }

    void Shader::SetFloat2(const str& name, const glm::vec2& value)
    {
        u32 location = glGetUniformLocation(mID, name.c_str());
        glUniform2f(location, value.x, value.y);
    }

    void Shader::SetFloat3(const str& name, const glm::vec3& value)
    {
        u32 location = glGetUniformLocation(mID, name.c_str());
        glUniform3f(location, value.x, value.y, value.z);
    }

    void Shader::SetFloat4(const str& name, const glm::vec4& value)
    {
        u32 location = glGetUniformLocation(mID, name.c_str());
        glUniform4f(location, value.x, value.y, value.z, value.w);
    }


    void Shader::SetMatrix3(const str& name, const glm::mat3& value)
    {
        u32 location = glGetUniformLocation(mID, name.c_str());
        glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

    void Shader::SetMatrix4(const str& name, const glm::mat4& value)
    {
        u32 location = glGetUniformLocation(mID, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

}