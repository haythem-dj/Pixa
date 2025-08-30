#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Core/Application.hpp"
#include "Pixa/Core/Logger.hpp"
#include "Pixa/Core/Window.hpp"

#include <memory>

namespace Pixa
{
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

        const std::unique_ptr<Logger>& GetLogger() const { return mLogger; }
        const std::unique_ptr<Window>& GetWindow() const { return mWindow; }

    private:
        Engine();

    private:
        b8 mRunning = false;

        Application* mApplication = nullptr;

        std::unique_ptr<Logger> mLogger;
        std::unique_ptr<Window> mWindow;

    private:
        static Engine* mInstance;
    };
}