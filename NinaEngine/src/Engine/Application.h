#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include <memory>

namespace Nina {
    
    class NINA_API Application {
    public:
        Application();
        virtual ~Application() = default;
        
        virtual void Run();
        void OnEvent(Event& Event);

    private:
        bool OnWindowClose(WindowCloseEvent& Event);

    private:
        std::unique_ptr<Window> Window;
        bool bIsRunning = true;
    };

    extern Application* CreateApplication();
    
}

