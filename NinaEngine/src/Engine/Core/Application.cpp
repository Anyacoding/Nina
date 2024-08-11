#include "ninapch.h"
#include "Application.h"
#include "Engine/Events/ApplicationEvent.h"


namespace Nina {
    
    Application::Application()
    {
        Application::App = this;
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
            NINA_CORE_LOG(warn, Event);  
        }
        
        while (bIsRunning)
        {
            for (Layer* Layer : LayerStack)
            {
                Layer->OnUpdate();
            }
            Window->OnUpdate();
        }
    }

    void Application::OnEvent(Event& Event)
    {
        NINA_CORE_LOG(trace, Event);
        
        EventDispatcher Dispatcher(Event);
        Dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& Event)
        {
            return this->OnWindowClose(Event);
        });
        
        for (auto It = LayerStack.rbegin(); It != LayerStack.rend(); ++It)
        {
            if (Event.bHandled)
            {
                break;
            }
            (*It)->OnEvent(Event);
        }
    }

    
    bool Application::OnWindowClose(WindowCloseEvent& Event)
    {
        bIsRunning = false;
        return true;
    }

    void Application::PushLayer(Layer* Layer)
    {
        LayerStack.PushLayer(Layer);
        Layer->OnAttach();
    }
    
    void Application::PushOverlay(Layer* Overlay)
    {
        LayerStack.PushOverlay(Overlay);
        Overlay->OnAttach();
    }
}
