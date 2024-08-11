#pragma once

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

    class NINA_API KeyTypedEvent: public KeyEvent
    {
    public:
        KeyTypedEvent(unsigned int Char): KeyEvent(static_cast<int>(Char)), InputCharacter(Char)
        {}

        unsigned int GetInputCharacter() const { return InputCharacter; }
        
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)

    private:
        unsigned int InputCharacter;
    };
}
