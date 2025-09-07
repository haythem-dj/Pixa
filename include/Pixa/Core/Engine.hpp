#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Core/Application.hpp"
#include "Pixa/Core/Logger.hpp"
#include "Pixa/Core/Window.hpp"
#include "Pixa/Core/Timer.hpp"

#include "Pixa/Graphics/Renderer.hpp"

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

        void Resize(u32 idth, u32 height);

        static Engine& GetInstance();

        void Stop() { mRunning = false; }

        u32 GetWidth() const { return mWindow->GetWindowProps().Width; }
        u32 GetHeight() const { return mWindow->GetWindowProps().Height; }

        const Logger& GetLogger() const { return *mLogger; }
        const Window& GetWindow() const { return *mWindow; }
        const Renderer& GetRenderer() const { return *mRenderer; }

    private:
        Engine();

    private:
        b8 mRunning = false;

        Timer mTimer;

        Application* mApplication = nullptr;

        std::unique_ptr<Logger> mLogger = nullptr;
        std::unique_ptr<Window> mWindow = nullptr;
        std::unique_ptr<Renderer> mRenderer = nullptr;

    private:
        static Engine* mInstance;
    };
}