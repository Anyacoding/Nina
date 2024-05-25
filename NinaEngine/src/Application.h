#pragma once

#include "Core.h"

namespace Nina {
    

    class NINA_API Application {
    public:
        Application();
        virtual ~Application();
        
    public:
        void Run();
    };
    
}

