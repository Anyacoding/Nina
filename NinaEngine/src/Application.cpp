#include "Application.h"
#include <iostream>

namespace Nina {
    
    Application::Application()
    {   

    }


    Application::~Application()
    {

    }

    void Nina::Application::Run()
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
