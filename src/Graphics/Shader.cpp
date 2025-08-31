#include "Pixa/pch.hpp"

#include "Pixa/Graphics/Shader.hpp"

#include "Pixa/Core/Engine.hpp"

#include <glad/gl.h>

#include <fstream>
#include <sstream>

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
}