#include <Nina.h>
#include <iostream>

#ifdef NINA_PLATFORM_WINDOWS
    #ifdef NINA_BUILD_DLL
        #define NINA_API __declspec(dllexport)
    #else
        #define NINA_API __declspec(dllimport)
    #endif
#else
    #error Nina only support Windows！
#endif

namespace Nina {

    void NINA_API Print();
    
}

class SandBox: public Nina::Application
{
public:
    void Run() override
    {
        while (true)
        {
            // std::cout << "hello Anya!" << "\n";
        }
    }
};

Nina::Application* Nina::CreateApplication()
{
    return new SandBox();
}




