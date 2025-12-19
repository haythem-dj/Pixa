#pragma once

#include "Pixa/Common/Defines.hpp"

#include <glm/glm.hpp>

namespace Pixa
{
    struct PIXA_API SpriteComponent
    {
        glm::vec2 UVStart{0.0f};
        glm::vec2 UVEnd{1.0f};        
    };
}