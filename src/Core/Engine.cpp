#include "Pixa/Core/Engine.hpp"
#include "Pixa/Core/Application.hpp"

#include <iostream>

namespace Pixa
{
    Engine* Engine::mInstance = nullptr;

    Engine::Engine()
        :mIsRunning(false), mLogger("Pixa")
    {
        mIsRunning = true;
    }

    Engine::~Engine()
    {
        
    }

    Engine& Engine::GetInstance()
    {
        if (!mInstance) mInstance = new Engine();
        return *mInstance;
    }

    void Engine::Run(Application* application)
    {
        if (!application)
        {
            std::cerr << "application is nullptr\n";
            return;
        }

        application->Init();

        while(mIsRunning)
        {

        }

        application->Shutdown();
    }
}