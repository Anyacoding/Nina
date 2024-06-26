#pragma once
#include "Engine/Core/Layer.h"

namespace Nina
{
    class NINA_API ImGuiLayer: public Layer
    {
    public:
        ImGuiLayer(): Layer("ImGuiLayer")
        {}
        
        ~ImGuiLayer() override = default;

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& Event) override;

    private:
        float PreTime = 0.0f;
    };
    
}
