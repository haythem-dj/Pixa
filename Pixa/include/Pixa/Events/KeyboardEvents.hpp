#pragma once

#include "Pixa/Events/Event.hpp"
#include "Pixa/Input/InputCodes.hpp"
#include <glm/glm.hpp>

namespace Pixa
{
    class KeyPressedEvent : public Event
    {
    public:
        KeyPressedEvent(Key key) : mKey(key) {}

        static EventType GetStaticType() { return EventType::KeyPressed; }
        EventType GetType() const override { return GetStaticType(); }

        Key GetKey() const { return mKey; }

    private:
        Key mKey;
    };

    class KeyReleasedEvent : public Event
    {
    public:
        KeyReleasedEvent(Key key) : mKey(key) {}

        static EventType GetStaticType() { return EventType::KeyReleased; }
        EventType GetType() const override { return GetStaticType(); }

        Key GetKey() const { return mKey; }

    private:
        Key mKey;
    };
} // namespace Pixa
