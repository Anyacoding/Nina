#include "ninapch.h"
#include "Application.h"
#include "Engine/Events/ApplicationEvent.h"
#include <GLFW/glfw3.h>


namespace Nina {
    
    Application::Application()
    {
        Window = std::unique_ptr<class Window>(Window::Create());
        Window->SetEventCallBack([this](Event& Event) -> void
        {
            this->OnEvent(Event);
        });
    }

    void Application::Run()
    {
        const WindowResizeEvent Event(1280, 720);

        if (Event.IsInCategory(EventCategoryApplication))
        {
            NINA_CORE_LOG(warn, Event.ToString());  
        }
        
        while (bIsRunning)
        {
            Window->OnUpdate();
        }
    }

    void Application::OnEvent(Event& Event)
    {
        EventDispatcher Dispatcher(Event);
        Dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& Event)
        {
            return this->OnWindowClose(Event);
        });
        
        NINA_CORE_LOG(trace, Event.ToString());
    }

    bool Application::OnWindowClose(WindowCloseEvent& Event)
    {
        bIsRunning = false;
        return true;
    }
}
