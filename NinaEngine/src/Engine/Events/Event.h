#pragma once
#include "Engine/Core.h"
#include <string>
#include <functional>
#include <concepts>

namespace Nina
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
        None                        = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };
    
    
    class NINA_API Event
    {
    private:
        friend class EventDispatcher;
        
    public:
        virtual ~Event() = default;

        virtual EventType GetEvenType() const = 0;
        virtual const std::string GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }
        
        bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }

        friend std::ostream& operator<<(std::ostream& os, const Event& e)
        {
            return os << e.ToString();
        }

    protected:
        bool bHandled = false;
    };

    template<class T>
    concept DerivedFromEvent = std::is_base_of_v<Event, T>;
    
    class EventDispatcher
    {
    private:
        template<class T>
        using EventFn = std::function<bool(T&)>;
    
    public:
        EventDispatcher(Event& Event): Event(Event)
        {}

        template<DerivedFromEvent T>
        bool Dispatch(EventFn<T> Func)
        {
            if (Event.GetEvenType() == T::GetStaticType())
            {
                Event.bHandled = Func(static_cast<T&>(Event));
                return true;
            }
            return false;
        }
    
    private:
        Event& Event;
    };

    


#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; } \
virtual EventType GetEvenType() const override { return GetStaticType(); } \
virtual const std::string GetName() const override { return #type; }
    
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
    
}
