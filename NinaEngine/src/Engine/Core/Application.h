#pragma once

#include "Core.h"
#include "Window.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Core/Layer.h"
#include "Engine/Core/LayerStack.h"
#include <memory>
#include <iostream>


namespace Nina {
    
    class NINA_API Application
    {
    public:
        virtual ~Application() = default;
        
        virtual void Run();
        virtual void OnEvent(Event& Event);

        void PushLayer(Layer* Layer);
        void PushOverlay(Layer* Overlay);

        Window& GetWindow() const { return *Window; }

    protected:
        Application();

    private:
        bool OnWindowClose(WindowCloseEvent& Event);

    private:
        std::unique_ptr<Window> Window;
        bool bIsRunning = true;
        LayerStack LayerStack;
    };

    extern Application* GetApplication();
    
}

