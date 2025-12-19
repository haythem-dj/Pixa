#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Graphics/Texture.hpp"

#include <memory>
#include <unordered_map>

namespace Pixa
{
    struct PIXA_API MaterialComponent
    {
        struct TextureBinding
        {
            std::shared_ptr<Texture> Texture = nullptr;
            u32 Slot = -1;
        };

        std::unordered_map<str, TextureBinding> Textures;
        
    };
}