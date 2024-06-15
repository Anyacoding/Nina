#include "ninapch.h"
#include "LayerStack.h"


namespace Nina
{
    LayerStack::LayerStack()
    {
        LayerInsert = Layers.begin();
    }
    
    LayerStack::~LayerStack()
    {
        for (Layer* Layer : Layers)
        {
            delete Layer;
        }
    }
    
    void LayerStack::PushLayer(Layer* Layer)
    {
        LayerInsert = Layers.emplace(LayerInsert, Layer);
    }
    
    void LayerStack::PushOverlay(Layer* Overlay)
    {
        Layers.emplace_back(Overlay);
    }
    
    void LayerStack::PopLayer(Layer* Layer)
    {
        auto It = std::find(Layers.begin(), Layers.end(), Layer);

        if (It != Layers.end())
        {
            Layers.erase(It);
            --LayerInsert;
        }
    }
    
    void LayerStack::PopOverlay(Layer* Overlay)
    {
        auto It = std::find(Layers.begin(), Layers.end(),  Overlay);

        if (It != Layers.end())
        {
            Layers.erase(It);
        }
    }
}
