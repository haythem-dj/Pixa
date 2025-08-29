#pragma once

#include "Pixa/Common/Defines.hpp"

namespace Pixa
{
    struct WindowProps
    {
        u32 Width;
        u32 Height;
        str Title;

        WindowProps()
            :Width(600), Height(600), Title("Pixa Engine")
        {}
    };
    
    class PIXA_API Window
    {
    public:
        Window(const WindowProps& windowProps = WindowProps());
        ~Window();

        explicit operator bool() const { return mWindow != nullptr; }

        void Update();
    
    private:
        void* mWindow = nullptr;
    
    };
}