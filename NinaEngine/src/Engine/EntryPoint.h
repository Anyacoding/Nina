#pragma once
#include "Application.h"

#ifdef NINA_PLATFORM_WINDOWS

int main()
{
    auto app = Nina::CreateApplication();
    app->Run();
    delete app;
}
    
#endif