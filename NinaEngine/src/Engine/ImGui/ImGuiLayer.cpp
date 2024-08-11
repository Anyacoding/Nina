#include "ninapch.h"
#include "ImGuiLayer.h"

#include "Engine/Core/Application.h"
#include "Engine/Core/Application.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "GLFW/glfw3.h"

namespace Nina
{
    void ImGuiLayer::OnAttach()
    {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& IO = ImGui::GetIO();
        IO.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        IO.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        IO.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
        IO.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
        IO.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
        IO.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
        IO.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
        IO.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
        IO.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
        IO.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
        IO.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
        IO.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
        IO.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        IO.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
        IO.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
        IO.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
        IO.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
        IO.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
        IO.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
        IO.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
        IO.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
        IO.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
        IO.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach()
    {
        
    }

    void ImGuiLayer::OnUpdate()
    {
        ImGuiIO& IO = ImGui::GetIO();
        const Application* App = Application::GetApplication();
        IO.DisplaySize = ImVec2(static_cast<float>(App->GetWindow().GetWidth()), static_cast<float>(App->GetWindow().GetHeight()));
        
        const float Time = static_cast<float>(glfwGetTime());
        IO.DeltaTime = PreTime > 0.0f ? (Time - PreTime) : (1.0f / 60.0f);
        PreTime = Time;
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();
        
        static bool Show = true;
        ImGui::ShowDemoWindow(&Show);
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    
    void ImGuiLayer::OnEvent(Event& Event)
    {
        EventDispatcher Dispatcher(Event);
        
        // Mouse Event
        Dispatcher.Dispatch<MouseButtonPressedEvent>(NINA_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressed));
        Dispatcher.Dispatch<MouseButtonReleasedEvent>(NINA_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleased));
        Dispatcher.Dispatch<MouseMovedEvent>(NINA_BIND_EVENT_FN(ImGuiLayer::OnMouseMoved));
        Dispatcher.Dispatch<MouseScrolledEvent>(NINA_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolled));
        // Key Event
        Dispatcher.Dispatch<KeyPressedEvent>(NINA_BIND_EVENT_FN(ImGuiLayer::OnKeyPressed));
        Dispatcher.Dispatch<KeyReleasedEvent>(NINA_BIND_EVENT_FN(ImGuiLayer::OnKeyReleased));
        Dispatcher.Dispatch<KeyTypedEvent>(NINA_BIND_EVENT_FN(ImGuiLayer::OnKeyTyped));
        // Window Event
        Dispatcher.Dispatch<WindowResizeEvent>(NINA_BIND_EVENT_FN(ImGuiLayer::OnWindowResize));
    }

    bool ImGuiLayer::OnMouseButtonPressed(MouseButtonPressedEvent& Event) const
    {
        ImGuiIO& IO = ImGui::GetIO();
        IO.MouseDown[Event.GetMouseButton()] = true;
        return false;
    }
    
    bool ImGuiLayer::OnMouseButtonReleased(MouseButtonReleasedEvent& Event) const
    {
        ImGuiIO& IO = ImGui::GetIO();
        IO.MouseDown[Event.GetMouseButton()] = false;
        return false;
    }
    
    bool ImGuiLayer::OnMouseMoved(MouseMovedEvent& Event) const
    {
        ImGuiIO& IO = ImGui::GetIO();
        IO.MousePos = ImVec2(Event.GetX(), Event.GetY());
        return false;
    }
    
    bool ImGuiLayer::OnMouseScrolled(MouseScrolledEvent& Event) const
    {
        ImGuiIO& IO = ImGui::GetIO();
        IO.MouseWheelH += Event.GetOffsetX();
        IO.MouseWheel += Event.GetOffsetY();
        return false;
    }
    
    bool ImGuiLayer::OnKeyPressed(KeyPressedEvent& Event) const
    {
        ImGuiIO& IO = ImGui::GetIO();
        IO.KeysDown[Event.GetKeyCode()] = true;
        
        IO.KeyCtrl = IO.KeysDown[GLFW_KEY_LEFT_CONTROL] || IO.KeysDown[GLFW_KEY_RIGHT_CONTROL];
        IO.KeyShift = IO.KeysDown[GLFW_KEY_LEFT_SHIFT]  || IO.KeysDown[GLFW_KEY_RIGHT_SHIFT];
        IO.KeyAlt = IO.KeysDown[GLFW_KEY_LEFT_ALT]      || IO.KeysDown[GLFW_KEY_RIGHT_ALT];
        IO.KeySuper = IO.KeysDown[GLFW_KEY_LEFT_SUPER]  || IO.KeysDown[GLFW_KEY_RIGHT_SUPER];
        
        return false;
    }
    
    bool ImGuiLayer::OnKeyReleased(KeyReleasedEvent& Event) const
    {
        ImGuiIO& IO = ImGui::GetIO();
        IO.KeysDown[Event.GetKeyCode()] = false;
        return false;
    }
    
    bool ImGuiLayer::OnKeyTyped(KeyTypedEvent& Event) const
    {
        ImGuiIO& IO = ImGui::GetIO();
        const unsigned InputCharacter = (Event.GetInputCharacter());
        if (InputCharacter > 0 && InputCharacter < 0x10000)
        {
            IO.AddInputCharacter(static_cast<unsigned short>(InputCharacter));
        }
        return false;
    }
    
    bool ImGuiLayer::OnWindowResize(WindowResizeEvent& Event) const
    {
        ImGuiIO& IO = ImGui::GetIO();
        IO.DisplaySize = ImVec2(static_cast<float>(Event.GetWidth()), static_cast<float>(Event.GetHeight()));
        IO.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        return false;
    }
}
