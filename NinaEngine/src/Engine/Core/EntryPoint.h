#pragma once
#include "Engine/Core/Application.h"

#ifdef NINA_PLATFORM_WINDOWS

int main(int __argc, char** __argv)
{
    Nina::Log::Init();
    NINA_CORE_LOG(err, "Init Engine!");
    NINA_LOG(info, "Hello Anya!");
    
    auto app = Nina::GetApplication();
    app->Run();
    delete app;
    
    return 0;
}

#endif
