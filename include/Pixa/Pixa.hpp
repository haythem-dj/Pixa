#pragma once

#include "Common/Defines.hpp"

#include <string>

namespace Pixa
{
    class PIXA_API PixaTest
    {
    public:
        PixaTest(const std::string& test);

        void Talk();

    private:
        std::string mTest;
    };
}