#include "ninapch.h"
#include "WindowsWindow.h"

namespace Nina
{
    bool WindowsWindow::bGLFWInitialized = false;
    
    WindowsWindow::WindowsWindow(const WindowProps& Props)
    {
        Init(Props);
    }

    WindowsWindow::~WindowsWindow()
    {
        ShutDown();
    }

    void WindowsWindow::OnUpdate()
    {
        glClearColor(1, 0, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        glfwSwapBuffers(GLwindow);
        bIsRunning = !glfwWindowShouldClose(GLwindow);
    }

    void WindowsWindow::SetVSync(bool bEnabled)
    {
        bEnabled ? glfwSwapInterval(1) : glfwSwapInterval(0);
        Data.bIsVSync = bEnabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return Data.bIsVSync;
    }

    void WindowsWindow::Init(const WindowProps& Props)
    {
        Data.Title = Props.Title;
        Data.Width = Props.Width;
        Data.Height = Props.Height;
        Data.bIsVSync = false;

        NINA_CORE_LOG(info, "Creating Window {0} ({1}, {2})", Data.Title, Data.Width, Data.Height);

        if (!bGLFWInitialized)
        {
            int Success = glfwInit();
            NINA_CORE_ASSERT(Success, "Could not intialize GLFW!");
            bGLFWInitialized = true;
        }

        GLwindow = glfwCreateWindow(Data.Width, Data.Height, Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(GLwindow);
        glfwSetWindowUserPointer(GLwindow, &Data);
        SetVSync(true);
    }

    void WindowsWindow::ShutDown()
    {
        glfwDestroyWindow(GLwindow);
    }
}
