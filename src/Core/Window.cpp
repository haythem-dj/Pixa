#include "Pixa/Core/Window.hpp"
#include "Pixa/Core/Engine.hpp"

#include <SDL3/SDL.h>

namespace Pixa
{
    Window::Window(const WindowProps& windowProps)
    {
        if (!SDL_Init(SDL_INIT_VIDEO))
        {
            PIXA_FATAL("Could not initialize SDL3. Error: {}", SDL_GetError());
            return;
        }

        SDL_Window* window = SDL_CreateWindow(windowProps.Title.c_str(), windowProps.Width, windowProps.Height, SDL_WINDOW_RESIZABLE);
        if (!window)
        {
            PIXA_FATAL("Could not create window. Error: {}", SDL_GetError());
            SDL_Quit();
            return;
        }

        mWindow = window;
    }

    Window::~Window()
    {
        if (!mWindow) return;
        
        SDL_DestroyWindow((SDL_Window*)mWindow);
        SDL_Quit();
    }

    void Window::Update()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                Engine::GetInstance().Stop();
            }
        }
    }
};