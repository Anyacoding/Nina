#include "ninapch.h"
#include "WindowsWindow.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"


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
            const int Success = glfwInit();
            NINA_CORE_ASSERT(Success, "Could not intialize GLFW!");
            bGLFWInitialized = true;
        }

        GLwindow = glfwCreateWindow(Data.Width, Data.Height, Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(GLwindow);
        glfwSetWindowUserPointer(GLwindow, &Data);
        SetVSync(true);
        

        // Set GLFW CallBacks
        glfwSetErrorCallback([](int error, const char* description) {
            NINA_CORE_LOG(err, "GLFW Error ({0}): {1}", error, description);
        });
        
        glfwSetWindowSizeCallback(GLwindow, [](GLFWwindow* Window, int W, int H) {
            WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(Window));
            data->Width = W;
            data->Height = H;

            WindowResizeEvent Event(W, H);
            data->EventCallback(Event);
        });

        glfwSetWindowCloseCallback(GLwindow, [](GLFWwindow* Window){
            WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(Window));
            WindowCloseEvent Event;
            data->EventCallback(Event);
        });

        glfwSetKeyCallback(GLwindow, [](GLFWwindow* Window, int Key, int Scancode, int Action, int Mods) {
            WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(Window));

            switch (Action)
            {
                case GLFW_PRESS: {
                    KeyPressedEvent Event(Key, 0);
                    data->EventCallback(Event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent Event(Key);
                    data->EventCallback(Event);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent Event(Key, 1);
                    data->EventCallback(Event);
                    break;
                }
                default:
                {
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(GLwindow, [](GLFWwindow* Window, int Button, int Action, int Mods) {
            WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(Window));

            switch (Action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent Event(Button);
                    data->EventCallback(Event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent Event(Button);
                    data->EventCallback(Event);
                    break;
                }
                default:
                {
                    break;
                }
            }
        });

        glfwSetScrollCallback(GLwindow, [](GLFWwindow* Window, double XOffset, double YOffset) {
            WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(Window));
            MouseScrolledEvent Event(static_cast<float>(XOffset), static_cast<float>(YOffset));
            data->EventCallback(Event);
        });
        
        glfwSetCursorPosCallback(GLwindow, [](GLFWwindow* Window, double XPos, double YPos) {
            WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(Window));
            MouseMovedEvent event(static_cast<float>(XPos), static_cast<float>(YPos));
            data->EventCallback(event);
        });
    }

    void WindowsWindow::ShutDown()
    {
        glfwDestroyWindow(GLwindow);
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
}
