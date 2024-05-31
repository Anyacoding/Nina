#pragma once

#include "Event.h"
#include "Engine/Core.h"
#include <sstream>

namespace Nina
{
    class NINA_API MouseMovedEvent: public Event
    {
    public:
        MouseMovedEvent(float X, float Y): MouseX(X), MouseY(Y)
        {}

        float GetX() const { return MouseX; }
        float GetY() const { return MouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << MouseX << ", " << MouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
        
    private:
        float MouseX, MouseY;
    };

    
    class NINA_API MouseScrolledEvent: public Event
    {
    public:
        MouseScrolledEvent(float XOffset, float YOffset): OffsetX(XOffset), OffsetY(YOffset)
        {}

        float GetOffsetX() const { return OffsetX; }
        float GetOffsetY() const { return OffsetY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEven: " << OffsetX << ", " << OffsetY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
        
    private:
        float OffsetX, OffsetY;
    };

    
    class NINA_API MouseButtonEvent: public Event
    {
    public:
        int GetMouseButton() const { return Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)

    protected:
        MouseButtonEvent(int Button): Button(Button)
        {}

    protected:
        int Button;
    };


    class NINA_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int Button): MouseButtonEvent(Button)
        {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class NINA_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int Button): MouseButtonEvent(Button)
        {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
    
}
