#pragma once

#include "Event.h"
#include "Engine/Core.h"
#include <sstream>

namespace Nina
{
    class NINA_API WindowResizeEvent: public Event
    {
    public:
        WindowResizeEvent(size_t Width, size_t Height): Width(Width), Height(Height)
        {}

        size_t GetWidth() const { return Width; }
        size_t GetHeight() const { return Height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << Width << ", " << Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    
    private:
        size_t Width, Height;
    };

    class NINA_API WindowCloseEvent: public Event
    {
    public:
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class NINA_API AppTickEvent : public Event
    {
    public:
        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class NINA_API AppUpdateEvent : public Event
    {
    public:
        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class NINA_API AppRenderEvent : public Event
    {
    public:
        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}



