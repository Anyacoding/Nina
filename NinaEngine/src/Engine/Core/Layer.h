#pragma once

#include "Engine/Events/Event.h"

namespace Nina
{
    class NINA_API Layer
    {
    public:
        Layer(std::string Name = "Layer"): DebugName(std::move(Name))
        {}
        
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& Event) {}

        const std::string& GetName() const { return DebugName; }

    protected:
        std::string DebugName;
    };
    
}
