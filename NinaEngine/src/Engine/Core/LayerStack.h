#pragma once

#include "Engine/Core/Layer.h"


namespace Nina
{
    class NINA_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* Layer);
        void PushOverlay(Layer* Overlay);
        void PopLayer(Layer* Layer);
        void PopOverlay(Layer* Overlay);

        std::vector<Layer*>::iterator begin() { return Layers.begin(); }
        std::vector<Layer*>::iterator end() { return Layers.end(); }
        std::vector<Layer*>::reverse_iterator rbegin() { return Layers.rbegin(); }
        std::vector<Layer*>::reverse_iterator rend() { return Layers.rend(); }

        std::vector<Layer*>::const_iterator begin() const { return Layers.begin(); }
        std::vector<Layer*>::const_iterator end() const { return Layers.end(); }
        std::vector<Layer*>::const_reverse_iterator rbegin() const { return Layers.rbegin(); }
        std::vector<Layer*>::const_reverse_iterator rend() const { return Layers.rend(); }

    private:
        std::vector<Layer*> Layers;
        std::vector<Layer*>::iterator LayerInsert;
    };
    
}
