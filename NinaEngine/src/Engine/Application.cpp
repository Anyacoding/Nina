#include "Application.h"
#include <iostream>

namespace Nina {

    void Application::Run()
    {
        while (true)
        {
            std::cout << "hello NinaEngine!" << "\n";
        }
    }

    void NINA_API Print()
    {
        std::cout << "hello NinaEngine!" << "\n";
    }
    
}
