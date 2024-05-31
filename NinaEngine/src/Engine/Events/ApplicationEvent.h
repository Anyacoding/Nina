#pragma once

#include "Event.h"
#include "Engine/Core.h"
#include "spdlog/spdlog.h"

#include <sstream>


namespace Nina
{
    class WindowResizeEvent: public Event
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

    class NINA_API WindowCloseEvent: Event
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


// namespace fmt {
//     template <>
//     struct formatter<Nina::WindowResizeEvent> {
//         // Parse format specifications if needed (here we ignore them)
//         // constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
//         //     return ctx.end();
//         // }
//
//         // Format the WindowResizeEvent
//         template <typename FormatContext>
//         auto format(const Nina::WindowResizeEvent& event, FormatContext& ctx) -> decltype(ctx.out()) {
//             return fmt::format_to(ctx.out(), "WindowResizeEvent(width={}, height={})", event.GetWidth(), event.GetHeight());
//         }
//     };
// }

