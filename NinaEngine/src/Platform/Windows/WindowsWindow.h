#pragma once

#include "Engine/Window.h"
#include <GLFW/glfw3.h>

namespace Nina
{
    class WindowsWindow: public Window
    {
    public:
        WindowsWindow(const WindowProps& Props);
        ~WindowsWindow() override;

        void OnUpdate() override;

        size_t GetWidth() const override { return Data.Width; }
        size_t GetHeight() const override { return Data.Height; }

        void SetEventCallBack(const EventCallBackFn& CallBack) override { Data.EventCallback = CallBack; }
        void SetVSync(bool bEnabled) override;
        bool IsVSync() const override;

    private:
        void Init(const WindowProps& Props);
        void ShutDown();

    private:
        struct WindowData
        {
            std::string Title;
            int Width;
            int Height;
            bool bIsVSync;
            EventCallBackFn EventCallback;
        };

        GLFWwindow* GLwindow;
        
        WindowData Data;

        static bool bGLFWInitialized;
    };
}
