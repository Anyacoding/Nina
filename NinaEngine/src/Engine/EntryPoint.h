#pragma once
#include "Application.h"
#include "Log.h"

#ifdef NINA_PLATFORM_WINDOWS

inline int main(int __argc, char** __argv)
{
    Nina::Log::Init();
    NINA_CORE_ERROR("Init Engine!");
    NINA_CLIENT_INFO("Hello Anya!");
    
    auto app = Nina::CreateApplication();
    app->Run();
    delete app;
}
    
#endif