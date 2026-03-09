#include "Pixa/pch.hpp"

#include "Pixa/Input/Input.hpp"

namespace Pixa
{
    void Input::ProcessKeys(Key key, b8 state) { Input::mKeys[key] = state; }

    void Input::ProcessMouse(MouseButton button, b8 state) { Input::mButtons[button] = state; }

    void Input::ProcessMousePosition(glm::vec2 position) { Input::mMousePosition = position; }

    void Input::ProcessScroll(i32 scroll) { Input::mScroll = scroll; }
} // namespace Pixa
