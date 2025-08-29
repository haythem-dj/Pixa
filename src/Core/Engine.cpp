#include "Pixa/pch.hpp"

#include "Pixa/Core/Engine.hpp"
#include "Pixa/Core/Application.hpp"

namespace Pixa
{
    Engine* Engine::mInstance = nullptr;

    Engine::Engine()
        :mLogger("Pixa")
    {
        if (!mWindow) return;
        mRunning = true;
    }

    Engine::~Engine()
    {
        
    }

    Engine& Engine::GetInstance()
    {
        if (!mInstance) mInstance = new Engine();
        return *mInstance;
    }

    void Engine::Update(f32 dt)
    {
        mWindow.Update();
    }

    void Engine::Render()
    {}

    void Engine::Run(Application* application)
    {
        if (!application)
        {
            PIXA_ERROR("application is null.");
            return;
        }

        application->Init();

        while(mRunning)
        {
            Update(1.f);
            Render();
        }

        application->Shutdown();
    }
}