#pragma once

#include <format>
#include <memory>
#include <string_view>

#include "Backend.hpp"
#include "LoggerConfig.hpp"

namespace CppTemplate {

class Logger {
public:
  static void init();
  static void init(const LoggerConfig &config);

  static void shutdown();

  static void setLevel(LogLevel level);

  template <typename... Args>
  static void log(LogLevel level, std::string_view file, int line,
                  std::string_view function, std::format_string<Args...> fmt,
                  Args &&...args) {
    auto message = std::format(fmt, std::forward<Args>(args)...);

    logMessage(level, file, line, function, message);
  }

private:
  static void logMessage(LogLevel level, std::string_view file, int line,
                         std::string_view function, std::string_view message);

  static std::unique_ptr<Backend> backend_;
};

} // namespace CppTemplate