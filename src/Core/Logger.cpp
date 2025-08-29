#include "Pixa/pch.hpp"

#include "Pixa/Core/Logger.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Pixa
{
    Logger::Logger(const str& name)
        :mName(name)
    {
        auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        sink->set_pattern("[%Y-%m-%d %H:%M:%S] [" + mName + "] [%^%l%$] %v");

        mLogger = std::make_shared<spdlog::logger>("engine_logger", sink);
        spdlog::register_logger(mLogger);
        spdlog::set_default_logger(mLogger);
        #ifdef PIXA_CONFIG_DEBUG
            spdlog::set_level(spdlog::level::trace);
        #else
            spdlog::set_level(spdlog::level::warn);
        #endif
    }

    Logger::~Logger()
    {
    
    }
}