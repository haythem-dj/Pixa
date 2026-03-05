#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Core/Timer.hpp"

namespace Pixa
{
    class PIXA_API ScopedTimer
    {
    public:
        ScopedTimer(const str& name);
        ~ScopedTimer();

    private:
        str mName;
        Timer mTimer;

    };
}