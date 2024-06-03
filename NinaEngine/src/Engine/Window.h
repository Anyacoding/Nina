#pragma once

#include "Engine/Core.h"
#include "Engine/Events/Event.h"

namespace Nina
{
    struct WindowProps
    {
    public:
        WindowProps(const std::string& Title = "Nina Engine", int W = 1280, int H = 720)
            : Title(Title), Width(W), Height(H)
        {}

    public:
        std::string Title;
        int Width;
        int Height;
    };

    
    class NINA_API Window
    {
    public:
        using EventCallBackFn = std::function<void(Event&)>;
        
    public:
        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual size_t GetWidth() const = 0;
        virtual size_t GetHeight() const = 0;

        virtual void SetEventCallBack(const EventCallBackFn& CallBack) = 0;
        virtual void SetVSync(bool bEnabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& Props = WindowProps());

    public:
        bool bIsRunning = true;
    };

}
