#include "ninapch.h"
#include "Application.h"
#include <GLFW/glfw3.h>


namespace Nina {
    
    Application::Application()
    {
        Window = std::unique_ptr<class Window>(Window::Create());
    }

    void Application::Run()
    {
        while (Window->bIsRunning)
        {
            Window->OnUpdate();
        }
    }
    
}
