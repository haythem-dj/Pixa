#pragma once

#include "Pixa/Common/Defines.hpp"

#include <spdlog/spdlog.h>
#include <memory>

namespace Pixa
{
    enum class LogType
    {
        Trace, Info, Debug, Warn, Error, Fatal
    };

    class PIXA_API Logger
    {
    public:
        Logger(const str& name);
        ~Logger();

        template<typename... Args>
        void Log(LogType logType, spdlog::format_string_t<Args...> message, Args&&... args) const
        {
            switch (logType)
            {
            case LogType::Trace:
                mLogger->trace(message, std::forward<Args>(args)...);
                break;

            case LogType::Debug:
                mLogger->debug(message, std::forward<Args>(args)...);
                break;
                
            case LogType::Info:
                mLogger->info(message, std::forward<Args>(args)...);
                break;
                
            case LogType::Warn:
                mLogger->warn(message, std::forward<Args>(args)...);
                break;

            case LogType::Error:
                mLogger->error(message, std::forward<Args>(args)...);
                break;
                
            case LogType::Fatal:
                mLogger->critical(message, std::forward<Args>(args)...);
                break;

            }
    }

    private:
        str mName;
        std::shared_ptr<spdlog::logger> mLogger = nullptr;
        
    };
}

#define PIXA_TRACE(...) ::Pixa::Engine::GetInstance().GetLogger()->Log(::Pixa::LogType::Trace, __VA_ARGS__)
#define PIXA_DEBUG(...) ::Pixa::Engine::GetInstance().GetLogger()->Log(::Pixa::LogType::Debug, __VA_ARGS__)
#define PIXA_INFO(...) ::Pixa::Engine::GetInstance().GetLogger()->Log(::Pixa::LogType::Info, __VA_ARGS__)
#define PIXA_WARN(...) ::Pixa::Engine::GetInstance().GetLogger()->Log(::Pixa::LogType::Warn, __VA_ARGS__)
#define PIXA_ERROR(...) ::Pixa::Engine::GetInstance().GetLogger()->Log(::Pixa::LogType::Error, __VA_ARGS__)
#define PIXA_FATAL(...) ::Pixa::Engine::GetInstance().GetLogger()->Log(::Pixa::LogType::Fatal, __VA_ARGS__)