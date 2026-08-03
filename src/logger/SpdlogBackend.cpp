// src/logger/SpdlogBackend.cpp

#include <CppTemplate/logger/SpdlogBackend.hpp>

#include <vector>

#include <spdlog/logger.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace CppTemplate {

namespace {

spdlog::level::level_enum toSpdlogLevel(LogLevel level) {
  switch (level) {
  case LogLevel::Trace:
    return spdlog::level::trace;
  case LogLevel::Debug:
    return spdlog::level::debug;
  case LogLevel::Info:
    return spdlog::level::info;
  case LogLevel::Warning:
    return spdlog::level::warn;
  case LogLevel::Error:
    return spdlog::level::err;
  case LogLevel::Critical:
    return spdlog::level::critical;
  case LogLevel::Off:
    return spdlog::level::off;
  }

  return spdlog::level::info;
}

} // namespace

SpdlogBackend::SpdlogBackend(const LoggerConfig &cfg)
    : flush_every_message_(cfg.flush_every_message) {

  std::vector<spdlog::sink_ptr> sinks;

  //
  // Console
  //
  if (cfg.console) {
    sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
  }

  //
  // File
  //
  if (cfg.file) {
    sinks.emplace_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
        cfg.file_name, cfg.max_file_size, cfg.max_files));
  }

  logger_ = std::make_shared<spdlog::logger>("CppTemplate", sinks.begin(),
                                             sinks.end());

  logger_->set_pattern(cfg.pattern);

  logger_->set_level(toSpdlogLevel(cfg.level));

  if (flush_every_message_) {
    logger_->flush_on(spdlog::level::trace);
  }
}

void SpdlogBackend::log(LogLevel level, std::string_view file, int line,
                        std::string_view function, std::string_view message) {

  if (!logger_) {
    return;
  }

  logger_->log(spdlog::source_loc{file.data(), line, function.data()},
               toSpdlogLevel(level), "{}", message);

  if (flush_every_message_) {
    logger_->flush();
  }
}

void SpdlogBackend::setLevel(LogLevel level) {
  if (logger_) {
    logger_->set_level(toSpdlogLevel(level));
  }
}

void SpdlogBackend::flush() {
  if (logger_) {
    logger_->flush();
  }
}

} // namespace CppTemplate
