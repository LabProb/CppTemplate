#pragma once

#include <memory>
#include <string_view>

#include <spdlog/logger.h>

#include "Backend.hpp"
#include "LoggerConfig.hpp"

namespace CppTemplate {

class SpdlogBackend : public Backend {
public:
  explicit SpdlogBackend(const LoggerConfig &cfg);

  void log(LogLevel level, std::string_view file, int line,
           std::string_view function, std::string_view message) override;

  void flush() override;

  void setLevel(LogLevel level) override;

private:
  std::shared_ptr<spdlog::logger> logger_;

  bool flush_every_message_;
};

} // namespace CppTemplate
