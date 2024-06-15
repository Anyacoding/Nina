#pragma once

#include "Engine/Core/Core.h"
#include "Event.h"

namespace Nina
{
    class NINA_API KeyEvent: public Event
    {
    public:
        int GetKeyCode() const { return KeyCode; }
        
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        KeyEvent(int KeyCode): KeyCode(KeyCode)
        {}

    protected:
        int KeyCode;
    };

    class NINA_API KeyPressedEvent: public KeyEvent
    {
    public:
        KeyPressedEvent(const int KeyCode, const int RepeatCount): KeyEvent(KeyCode), RepeatCount(RepeatCount)
        {}

        int GetRepeatCount() const { return RepeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << KeyCode << " (" << RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        int RepeatCount;
    };

    class NINA_API KeyReleasedEvent: public KeyEvent
    {
    public:
        KeyReleasedEvent(const int KeyCode): KeyEvent(KeyCode)
        {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}
