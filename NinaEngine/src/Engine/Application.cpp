#include "Application.h"
#include "Engine/Events/ApplicationEvent.h"
#include <iostream>

#include "Log.h"

namespace Nina {
    
    void Application::Run()
    {
        WindowResizeEvent Event(1280, 720);

        if (Event.IsInCategory(EventCategoryApplication))
        {
            NINA_CORE_TRACE(Event.ToString());
        }

        if (Event.IsInCategory(EventCategoryInput))
        {
            NINA_CORE_TRACE(Event.ToString());
        }
        
        while (true);
    }
    
}
