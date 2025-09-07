#include "Pixa/pch.hpp"

#include "Pixa/Core/Engine.hpp"
#include "Pixa/Core/Application.hpp"

#include <glad/gl.h>

namespace Pixa
{
    Engine* Engine::mInstance = nullptr;

    Engine::Engine()
    {
        mLogger = std::make_unique<Logger>("Pixa");
        mWindow = std::make_unique<Window>();
        if (!*mWindow) return;

        mRenderer = std::make_unique<Renderer>(*mWindow);
        mRenderer->SetClearColor({1.f, 1.f, 1.f, 1.f});

        mRunning = true;
    }

    Engine::~Engine()
    {
        mLogger.reset();
        mWindow.reset();
        mRenderer.reset();
    }

    Engine& Engine::GetInstance()
    {
        if (!mInstance) mInstance = new Engine();
        return *mInstance;
    }

    void Engine::Update(f32 dt)
    {
        mWindow->Update();
        mApplication->Update(dt);
    }

    void Engine::Render()
    {
        mApplication->Render();
    }

    void Engine::Run(Application* application)
    {
        if (!application)
        {
            PIXA_ERROR("application is null.");
            return;
        }

        mApplication = application;

        mApplication->Init();

        f32 dt = 1.f;
        while(mRunning)
        {
            mTimer.Reset();
            Update(dt);
            Render();
            dt = (f32)mTimer.Elapsed();
        }

        mApplication->Shutdown();
    }

    void Engine::Resize(u32 width, u32 height)
    {
        mApplication->Resize(width, height);
    }
}