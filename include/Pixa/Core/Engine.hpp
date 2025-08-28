#pragma once

#include "Pixa/Common/Defines.hpp"

namespace Pixa
{
    class Application;

    class PIXA_API Engine
    {
    public:
        ~Engine();
        Engine(const Engine&) = delete;
        Engine& operator=(const Engine&) = delete;

        void Run(Application* application);

        static Engine& GetInstance();

    private:
        Engine();

    private:
        b8 mIsRunning;

    private:
        static Engine* mInstance;
    };
}