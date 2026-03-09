#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Input/InputCodes.hpp"

#include <glm/glm.hpp>

#include <unordered_map>

namespace Pixa
{
    class PIXA_API Input
    {
        friend class Window;

    public:
        static b8 IsKeyDown(Key key) { return mKeys[key]; }
        static b8 IsKeyUp(Key key) { return !mKeys[key]; }

        static b8 IsMouseDown(MouseButton button) { return mButtons[button]; }
        static b8 IsMouseUp(MouseButton button) { return !mButtons[button]; }

        static glm::vec2 GetMousePosition() { return mMousePosition; }

        static i32 GetScroll() { return mScroll; }

    private:
        static void ProcessKeys(Key key, b8 state);
        static void ProcessMouse(MouseButton button, b8 state);
        static void ProcessMousePosition(glm::vec2 position);
        static void ProcessScroll(i32 scroll);

    private:
        static inline std::unordered_map<Key, b8> mKeys;
        static inline std::unordered_map<MouseButton, b8> mButtons;
        static inline glm::vec2 mMousePosition{0.0f};
        static inline i32 mScroll = 0;
    };

} // namespace Pixa
