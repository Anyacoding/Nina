#pragma once

#include "Core.h"
#include "Window.h"
#include <memory>

namespace Nina {
    
    class NINA_API Application {
    public:
        Application();
        virtual ~Application() = default;
        
    public:
        virtual void Run();

    private:
        std::unique_ptr<Window> Window;
    };

    extern Application* CreateApplication();
    
}

