#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Nina
{
    class NINA_API Log {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& GetCoreLogger()
        {
            return CoreLogger;
        }

        static std::shared_ptr<spdlog::logger>& GetClientLogger()
        {
            return ClientLogger;
        }

    private:
        static std::shared_ptr<spdlog::logger> CoreLogger;
        static std::shared_ptr<spdlog::logger> ClientLogger;
    };
}


// Core Log
#define NINA_CORE_INFO(...)        ::Nina::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NINA_CORE_TRACE(...)       ::Nina::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NINA_CORE_ERROR(...)       ::Nina::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NINA_CORE_WARN(...)        ::Nina::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NINA_CORE_LOG(type, ...)   ::Nina::Log::GetCoreLogger()->log(spdlog::level::type, __VA_ARGS__)


// Client Log
#define NINA_ERROR(...)            ::Nina::Log::GetClientLogger()->error(__VA_ARGS__)
#define NINA_WARN(...)             ::Nina::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NINA_INFO(...)             ::Nina::Log::GetClientLogger()->info(__VA_ARGS__)
#define NINA_TRACE(...)            ::Nina::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NINA_LOG(type, ...)        ::Nina::Log::GetClientLogger()->log(spdlog::level::type, __VA_ARGS__)




