#pragma once

#include "Pixa/Common/Defines.hpp"

#include <filesystem>
#include <memory>

namespace Pixa
{
    class PIXA_API Texture
    {
    public:
        ~Texture();
        
        explicit operator bool() const { return mID != 0; }
        
        void Bind(u32 slot = 0) const;
        void Unbind() const;
        
        u32 GetID() const { return mID; }
    
        static std::shared_ptr<Texture> Create(const std::filesystem::path& texturePath);
        
    private:
        Texture(const std::filesystem::path& texturePath);

    private:
        u32 mID = 0;
    };
}