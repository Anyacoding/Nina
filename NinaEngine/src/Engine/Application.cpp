#include "Application.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Log.h"

namespace Nina {
    
    void Application::Run()
    {
        WindowResizeEvent Event(1280, 720);

        if (Event.IsInCategory(EventCategoryApplication))
        {
            NINA_CORE_LOG(critical, Event.ToString());
        }

        if (Event.IsInCategory(EventCategoryInput))
        {
            NINA_CORE_LOG(trace, Event.ToString());
        }
        
        while (true);
    }
    
}
