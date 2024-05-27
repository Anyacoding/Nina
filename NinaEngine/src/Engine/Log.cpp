#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Nina
{
    std::shared_ptr<spdlog::logger> Log::CoreLogger;
    std::shared_ptr<spdlog::logger> Log::ClientLogger;
    
    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        
        CoreLogger = spdlog::stdout_color_mt("Nina");
        CoreLogger->set_level(spdlog::level::level_enum::trace);

        ClientLogger = spdlog::stdout_color_mt("App");
        ClientLogger->set_level(spdlog::level::level_enum::trace);
    }
}

