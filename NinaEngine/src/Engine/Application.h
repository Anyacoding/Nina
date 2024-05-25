#pragma once

#include "Core.h"

namespace Nina {
    
    class NINA_API Application {
    public:
        Application();
        virtual ~Application();
        
    public:
        virtual void Run();
    };

    extern Application* CreateApplication();
    
}

