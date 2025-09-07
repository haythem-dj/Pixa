#include "Pixa/Core/Timer.hpp"

namespace Pixa
{
    Timer::Timer()
    {
        Reset();
    }

    Timer::~Timer()
    {}

    f64 Timer::Elapsed()
    {
        TimePoint end = Clock::now();
        std::chrono::duration<f64> duration = end - mStart;
        return duration.count();
    }

    f64 Timer::ElapsedMilli()
    {
        TimePoint end = Clock::now();
        std::chrono::duration<f64, std::milli> duration = end - mStart;
        return duration.count();
    }

    void Timer::Reset()
    {
        mStart = Clock::now();
    }

    f64 Timer::GetSeconds()
    {
        TimePoint now = Clock::now();
        return std::chrono::duration<f64>(now.time_since_epoch()).count();
    }

    f64 Timer::GetMilliSeconds()
    {
        TimePoint now = Clock::now();
        return std::chrono::duration<f64, std::milli>(now.time_since_epoch()).count();
    }
}