#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Core/Logger.hpp"

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

        Logger& GetLogger() { return mLogger; }

    private:
        Engine();

    private:
        b8 mIsRunning;

        Logger mLogger;

    private:
        static Engine* mInstance;
    };
}