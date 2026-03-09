#pragma once

#include "Pixa/Common/Defines.hpp"

namespace Pixa
{
    enum class EventType
    {
        None = 0,

        KeyPressed,
        KeyReleased,

        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled,

        WindowClose,
        WindowResize
    };

    class Event
    {
        friend class EventDispatcher;

    public:
        Event() = default;
        virtual ~Event() = default;
        virtual EventType GetType() const;

    private:
        b8 mHandled = false;
    };

    class EventDispatcher
    {
    public:
        EventDispatcher(Event& e) : mEvent(e) {}
        template <typename T, typename F>
        bool Dispactch(const F& func)
        {
            if (mEvent.GetType() == T::GetStaticType())
            {
                mEvent.mHandled |= func((T&)mEvent);
                return true;
            }
            return false;
        }

    private:
        Event& mEvent;
    };

} // namespace Pixa
