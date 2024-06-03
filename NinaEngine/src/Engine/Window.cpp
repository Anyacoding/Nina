#include "ninapch.h"
#include "Window.h"

#ifdef NINA_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsWindow.h"
#endif


namespace Nina
{
    Window* Window::Create(const WindowProps& Props)
    {
    #ifdef NINA_PLATFORM_WINDOWS
        return new WindowsWindow(Props);
    #else
        NINA_CORE_ASSERT(false, "Unknown platform!");
        return nullptr;
    #endif
    }
}
