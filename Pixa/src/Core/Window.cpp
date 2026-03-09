#include "Pixa/Events/KeyboardEvents.hpp"
#include "Pixa/Events/MouseEvents.hpp"
#include "Pixa/Events/WindowEvents.hpp"
#include "Pixa/pch.hpp"

#include "Pixa/Core/Engine.hpp"
#include "Pixa/Core/Window.hpp"

#include "Pixa/Input/Input.hpp"

#include <SDL3/SDL.h>
#include <glad/glad.h>

namespace Pixa
{
    Window::Window(const WindowProps& windowProps) : mWindowProps(windowProps)
    {
        if (!SDL_Init(SDL_INIT_VIDEO))
        {
            PIXA_FATAL("Could not initialize SDL3. Error: {}", SDL_GetError());
            return;
        }

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        SDL_Window* window = SDL_CreateWindow(
            windowProps.Title.c_str(), windowProps.Width, windowProps.Height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

        if (!window)
        {
            PIXA_FATAL("Could not create window. Error: {}", SDL_GetError());
            return;
        }

        SDL_GLContext context = SDL_GL_CreateContext(window);
        if (context == NULL)
        {
            PIXA_FATAL("Could not create gl context");
            return;
        }
        mContext = (void*)&(context);
        SDL_GL_MakeCurrent(window, *(SDL_GLContext*)mContext);

        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            PIXA_FATAL("Could not initialize glad");
            return;
        }

        mWindow = window;
    }

    Window::~Window()
    {
        if (mContext) SDL_GL_DestroyContext(*(SDL_GLContext*)mContext);
        if (mWindow) SDL_DestroyWindow((SDL_Window*)mWindow);
        SDL_Quit();
    }

    void Window::Update()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
            {
                WindowCloseEvent wc;
                Engine::GetInstance().OnEvent(wc);
            }
            break;

            case SDL_EVENT_KEY_DOWN:
            {
                KeyPressedEvent kp((Key)event.key.key);
                Engine::GetInstance().OnEvent(kp);
                Input::ProcessKeys((Key)event.key.key, true);
            }
            break;

            case SDL_EVENT_KEY_UP:
            {
                KeyReleasedEvent kr((Key)event.key.key);
                Engine::GetInstance().OnEvent(kr);
                Input::ProcessKeys((Key)event.key.key, false);
            }
            break;

            case SDL_EVENT_MOUSE_BUTTON_DOWN:
            {
                MousePressedEvent mp((MouseButton)event.button.button);
                Engine::GetInstance().OnEvent(mp);
                Input::ProcessMouse((MouseButton)event.button.button, true);
            }
            break;

            case SDL_EVENT_MOUSE_BUTTON_UP:
            {
                MouseReleasedEvent mr((MouseButton)event.button.button);
                Engine::GetInstance().OnEvent(mr);
                Input::ProcessMouse((MouseButton)event.key.key, false);
            }
            break;

            case SDL_EVENT_MOUSE_MOTION:
            {
                MouseMovedEvent mm({event.motion.x, event.motion.y});
                Engine::GetInstance().OnEvent(mm);
                Input::ProcessMousePosition({event.motion.x, event.motion.y});
            }
            break;

            case SDL_EVENT_MOUSE_WHEEL:
            {
                i32 scrolled = event.wheel.y > 0 ? 1 : (event.wheel.y < 0 ? -1 : 0);
                MouseScrolledEvent ms(scrolled);
                Engine::GetInstance().OnEvent(ms);
                Input::ProcessScroll(event.wheel.y > 0 ? 1 : (event.wheel.y < 0 ? -1 : 0));
            }
            break;

            case SDL_EVENT_WINDOW_RESIZED:
            {
                mWindowProps.Width = event.window.data1;
                mWindowProps.Height = event.window.data2;
                WindowResizeEvent wr(event.window.data1, event.window.data2);
                Engine::GetInstance().OnEvent(wr);
            }
            break;
            default:
                break;
            }
        }
    }

    void Window::SwapBuffers() const { SDL_GL_SwapWindow((SDL_Window*)mWindow); }
}; // namespace Pixa
