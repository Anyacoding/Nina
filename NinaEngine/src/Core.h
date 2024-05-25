#pragma once

// #define NINA_BUILD_DLL
// #define NINA_PLATFORM_WINDOWS

#ifdef NINA_PLATFORM_WINDOWS
    #ifdef NINA_BUILD_DLL
        #define NINA_API __declspec(dllexport)
    #else
        #define NINA_API __declspec(dllimport)
    #endif
#else
    // #error Nina only support Windows！
#endif
