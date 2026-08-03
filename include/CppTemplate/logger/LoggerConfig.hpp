#pragma once

#include <string>

#include "LogLevel.hpp"

namespace CppTemplate {

struct LoggerConfig {
  //
  // Console
  //

  bool console{true};
  bool color{true};

  //
  // File
  //

  bool file{false};
  std::string file_name{"CppTemplate.log"};

  std::size_t max_file_size{5 * 1024 * 1024};
  std::size_t max_files{3};

  //
  // Log level
  //

#ifndef NDEBUG
  LogLevel level{LogLevel::Debug};
#else
  LogLevel level{LogLevel::Info};
#endif

  //
  // Behaviour
  //

  bool flush_every_message{false};
  bool utc_time{false};

  //
  // Formatting
  //

  std::string pattern{"%Y-%m-%d %H:%M:%S.%e [%^%l%$] [thread %t] [%s:%#] %v"};
};

} // namespace CppTemplate
