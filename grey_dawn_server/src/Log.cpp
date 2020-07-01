
#include "Log.h"
#include <spdlog/cfg/env.h>
#include <spdlog/async.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>


#define GDS_SPDLOG_USE_THREADPOOL
#define ROTATING_LOGGER_MAX_FILE_SIZE (5 * 1024 * 1024)

void Initialize_spdlog()
{
	spdlog::init_thread_pool(8192, 1);
	std::vector<spdlog::sink_ptr> sinks;
	sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
	sinks.push_back(std::make_shared<spdlog::sinks::daily_file_sink_mt>("logs/daily_logger_mt.log", 23, 59));
#ifdef GDS_SPDLOG_USE_THREADPOOL
	auto defaultLogger = std::make_shared<spdlog::async_logger>("default", std::begin(sinks), std::end(sinks), spdlog::thread_pool());
#else
	auto defaultLogger = std::make_shared<spdlog::logger>("default", std::begin(sinks), std::end(sinks));
#endif
	spdlog::register_logger(defaultLogger);
	spdlog::set_default_logger(defaultLogger);
}

void Shutdown_spdlog()
{
	spdlog::shutdown();
}