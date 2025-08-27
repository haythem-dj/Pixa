#include "Pixa/Pixa.hpp"

#include <iostream>

namespace Pixa
{
    PixaTest::PixaTest(const std::string& test)
        :mTest(test)
    {}

    void PixaTest::Talk()
    {
        std::cout << mTest << std::endl;
    }
}