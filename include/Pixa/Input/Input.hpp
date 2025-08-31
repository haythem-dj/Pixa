#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Input/InputCodes.hpp"

#include <glm/glm.hpp>

#include <unordered_map>

namespace Pixa
{
    class PIXA_API Input
    {
    friend void ProcessKeys(Key key, b8 state);
    friend void ProcessMouse(MouseButton button, b8 state);
    friend void ProcessMousePosition(glm::vec2 position);
    friend void ProcessScroll(i32 scroll);

    public:
        static b8 IsKeyDown(Key key) { return mKeys[key]; }
        static b8 IsKeyUp(Key key) { return !mKeys[key]; }

        static b8 IsMouseDown(MouseButton button) { return mButtons[button]; }
        static b8 IsMouseUp(MouseButton button) { return !mButtons[button]; }

        static glm::vec2 GetMousePosition() { return mMousePosition; }

        static i32 GetScroll() { return mScroll; }

    private:
        static inline std::unordered_map<Key, b8> mKeys;
        static inline std::unordered_map<MouseButton, b8> mButtons;
        static inline glm::vec2 mMousePosition{0.0f};
        static inline i32 mScroll = 0;
    };

    void ProcessKeys(Key key, b8 state);
    void ProcessMouse(MouseButton button, b8 state);
    void ProcessMousePosition(glm::vec2 position);
    void ProcessScroll(i32 scroll);
}