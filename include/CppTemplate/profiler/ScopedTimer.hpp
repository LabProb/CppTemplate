#pragma once

#include <chrono>
#include <string>
#include <string_view>

namespace CppTemplate {

class ScopedTimer {
public:
  ScopedTimer(std::string_view name, std::string_view file, int line,
              std::string_view function);

  ~ScopedTimer() noexcept;

private:
  std::string name_;

  std::chrono::steady_clock::time_point start_;

  std::string_view file_;
  int line_;
  std::string_view function_;
};

} // namespace CppTemplate
