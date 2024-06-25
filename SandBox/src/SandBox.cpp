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


class ExampleLayer: public Nina::Layer
{
public:
    ExampleLayer(): Layer("Example")
    {}

    void OnUpdate() override
    {
        NINA_LOG(info, "ExampleLayer::Update");
    }

    void OnEvent(Nina::Event& Event) override
    {
        NINA_LOG(trace, Event.ToString());
    }

};

class SandBox: public Nina::Application
{
public:
    SandBox()
    {
        PushLayer(new ExampleLayer());
    }

};

Nina::Application* Nina::CreateApplication()
{
    return new SandBox();
}






