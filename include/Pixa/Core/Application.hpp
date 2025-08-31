#pragma once

#include "Pixa/Common/Defines.hpp"

namespace Pixa
{
    class PIXA_API Application
    {
    public:
        virtual ~Application() = default;

        virtual void Init() {};
        virtual void Shutdown() {};
        virtual void Update(f32 dt) { (void)dt; };
        virtual void Render() {};
    };
}