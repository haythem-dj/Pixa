#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Core/Logger.hpp"
#include "Pixa/Core/Window.hpp"

namespace Pixa
{
    class Application;

    class PIXA_API Engine
    {
    public:
        ~Engine();
        Engine(const Engine&) = delete;
        Engine& operator=(const Engine&) = delete;

        void Update(f32 dt);
        void Render();

        void Run(Application* application);

        static Engine& GetInstance();

        void Stop() { mRunning = false; }

        const Logger& GetLogger() const { return mLogger; }
        const Window& GetWindow() const { return mWindow; }

    private:
        Engine();

    private:
        b8 mRunning = false;

        Logger mLogger;
        Window mWindow;

    private:
        static Engine* mInstance;
    };
}