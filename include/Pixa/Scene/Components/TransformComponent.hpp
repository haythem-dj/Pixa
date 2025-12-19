#pragma once

#include "Pixa/Common/Defines.hpp"

#include <glm/glm.hpp>

namespace Pixa
{
    struct PIXA_API TransformComponent
    {
        glm::vec2 Position{0.0f};
        glm::vec2 Scale{1.0f};
        f32 Rotation{0.0f};
    };
}