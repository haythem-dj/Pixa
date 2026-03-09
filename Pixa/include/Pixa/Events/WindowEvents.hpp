#pragma once

#include "Event.hpp"

namespace Pixa
{
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;
        static EventType GetStaticType() { return EventType::WindowClose; }
        EventType GetType() const override { return GetStaticType(); }
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(u32 width, u32 height) : mWidth(width), mHeight(height) {}

        static EventType GetStaticType() { return EventType::WindowResize; }
        EventType GetType() const override { return GetStaticType(); }

        u32 GetWidth() const { return mWidth; }
        u32 GetHeight() const { return mHeight; }

    private:
        u32 mWidth, mHeight;
    };
} // namespace Pixa
