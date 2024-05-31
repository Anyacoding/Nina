#pragma once
#include "Engine/Core.h"
#include "Engine/Application.h"


#ifdef NINA_PLATFORM_WINDOWS

int main(int __argc, char** __argv)
{
    Nina::Log::Init();
    NINA_CORE_ERROR("Init Engine!");
    NINA_CLIENT_INFO("Hello Anya!");
    
    auto app = Nina::CreateApplication();
    app->Run();
    delete app;
    
    return 0;
}
    
#endif