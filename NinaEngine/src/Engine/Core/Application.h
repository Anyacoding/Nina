#pragma once
#include "Core.h"
#include "Window.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Core/Layer.h"
#include "Engine/Core/LayerStack.h"
#include <memory>

namespace Nina {
    
    class NINA_API Application
    {
    public:
        Application(const Application&) = delete;
        Application& operator=(const Application&) = delete;
        
        virtual void Run();
        virtual void OnEvent(Event& Event);

        void PushLayer(Layer* Layer);
        void PushOverlay(Layer* Overlay);

        Window& GetWindow() const { return *Window; }

        static Application* GetApplication()
        {
            NINA_CORE_ASSERT(App, "Application not exists!")
            return App;
        }

    protected:
        Application();
        virtual ~Application() = default;
    
    private:
        bool OnWindowClose(WindowCloseEvent& Event);

    private:
        std::unique_ptr<Window> Window;
        bool bIsRunning = true;
        LayerStack LayerStack;

    protected:
        inline static Application* App = nullptr;
    };

    extern Application* CreateApplication();
    
}

