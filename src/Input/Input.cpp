#include "Pixa/Input/Input.hpp"

namespace Pixa
{
    void ProcessKeys(Key key, b8 state)
    {
        Input::mKeys[key] = state;
    }

    void ProcessMouse(MouseButton button, b8 state)
    {
        Input::mButtons[button] = state;
    }

    void ProcessMousePosition(glm::vec2 position)
    {
        Input::mMousePosition = position;
    }

    void ProcessScroll(i32 scroll)
    {
        Input::mScroll = scroll;
    }
}