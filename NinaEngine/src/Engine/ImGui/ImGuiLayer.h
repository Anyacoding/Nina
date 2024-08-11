#pragma once
#include "Engine/Core/Layer.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

namespace Nina
{
    class NINA_API ImGuiLayer: public Layer
    {
    public:
        ImGuiLayer(): Layer("ImGuiLayer")
        {}

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& Event) override;

    private:
        bool OnMouseButtonPressed(MouseButtonPressedEvent& Event) const;
        bool OnMouseButtonReleased(MouseButtonReleasedEvent& Event) const;
        bool OnMouseMoved(MouseMovedEvent& Event) const;
        bool OnMouseScrolled(MouseScrolledEvent& Event) const;
        bool OnKeyPressed(KeyPressedEvent& Event) const;
        bool OnKeyReleased(KeyReleasedEvent& Event) const;
        bool OnKeyTyped(KeyTypedEvent& Event) const;
        bool OnWindowResize(WindowResizeEvent& Event) const;

    private:
        float PreTime = 0.0f;
    };
    
}
