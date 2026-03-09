#pragma once

#include "Pixa/Events/Event.hpp"
#include "Pixa/Input/InputCodes.hpp"

#include <glm/glm.hpp>

namespace Pixa
{
    class MousePressedEvent : public Event
    {
    public:
        MousePressedEvent(MouseButton button) : mButton(button) {}

        static EventType GetStaticType() { return EventType::MouseButtonPressed; }
        EventType GetType() const override { return GetStaticType(); }

        MouseButton GetButton() const { return mButton; }

    private:
        MouseButton mButton;
    };

    class MouseReleasedEvent : public Event
    {
    public:
        MouseReleasedEvent(MouseButton button) : mButton(button) {}

        static EventType GetStaticType() { return EventType::MouseButtonReleased; }
        EventType GetType() const override { return GetStaticType(); }

        MouseButton GetButton() const { return mButton; }

    private:
        MouseButton mButton;
    };

    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(const glm::vec2& position) : mPosition(position) {}

        static EventType GetStaticType() { return EventType::MouseMoved; }
        EventType GetType() const override { return GetStaticType(); }
        const glm::vec2& GetPosition() const { return mPosition; }

    private:
        glm::vec2 mPosition;
    };

    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(i32 scroll) : mScroll(scroll) {}

        static EventType GetStaticType() { return EventType::MouseScrolled; }
        EventType GetType() const override { return GetStaticType(); }
        const glm::vec2& GetScroll() const { return mScroll; }

    private:
        glm::vec2 mScroll;
    };
} // namespace Pixa
