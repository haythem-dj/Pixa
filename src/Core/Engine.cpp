#include "Pixa/Core/Engine.hpp"
#include "Pixa/Core/Application.hpp"

#include <iostream>

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
            std::cerr << "application is nullptr\n";
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