#pragma once

#include "Pixa/Common/Defines.hpp"

#include <chrono>

namespace Pixa
{
    class PIXA_API Timer
    {
        using Clock = std::chrono::high_resolution_clock;
        using TimePoint = std::chrono::time_point<Clock>;
        
    public:
        Timer();
        ~Timer();

        f64 Elapsed();
        f64 ElapsedMilli();
        void Reset();

        static f64 GetSeconds();
        static f64 GetMilliSeconds();

    private:
        TimePoint mStart;
    
    };
}