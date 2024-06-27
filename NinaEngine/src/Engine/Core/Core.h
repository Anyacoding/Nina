#pragma once

#ifdef NINA_PLATFORM_WINDOWS
    #ifdef NINA_BUILD_DLL
        #define NINA_API __declspec(dllexport)
    #else
        #define NINA_API __declspec(dllimport)
    #endif
#else
    #error Nina only support Windows！
#endif

#ifdef NINA_DEBUG
    #define NINA_ENABLE_ASSERTS
#endif

#ifdef NINA_ENABLE_ASSERTS
    #define NINA_ASSERT(x, ...) { if(!(x)) { NINA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define NINA_CORE_ASSERT(x, ...) { if(!(x)) { NINA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define NINA_ASSERT(x, ...) 
    #define NINA_CORE_ASSERT(x, ...) 
#endif

#define BIT(x) (1 << (x))


template<class T>
class Singleton
{
public:
    static T* Instance()
    {
        static T Instance;
        return &Instance;
    }
};





