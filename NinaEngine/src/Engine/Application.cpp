#include "ninapch.h"
#include "Application.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Log.h"

namespace Nina {
    
    void Application::Run()
    {
        WindowResizeEvent Event(1280, 720);

        if (Event.IsInCategory(EventCategoryApplication))
        {
            NINA_CORE_LOG(warn, Event.ToString());  
        }

        if (Event.IsInCategory(EventCategoryInput))
        {
            NINA_CORE_LOG(err, Event.ToString());
        }
        
        while (true);
    }
    
}
