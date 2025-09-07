#include "Pixa/pch.hpp"

#include "Pixa/Core/ScopedTimer.hpp"
#include "Pixa/Core/Engine.hpp"

namespace Pixa
{
    ScopedTimer::ScopedTimer(const str& name)
        :mName(name)
    {}

    ScopedTimer::~ScopedTimer()
    {
        f64 elapsed = mTimer.Elapsed();
        f64 elapsedMilli = mTimer.ElapsedMilli();
        PIXA_TRACE("[TIMER] {} : {}s  |  {}ms", mName, elapsed, elapsedMilli);
    }
}