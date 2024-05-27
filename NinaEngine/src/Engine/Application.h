#pragma once

#include "Core.h"

namespace Nina {
    
    class NINA_API Application {
    public:
        Application() = default;
        virtual ~Application() = default;
        
    public:
        virtual void Run();
    };

    extern Application* CreateApplication();
    
}

