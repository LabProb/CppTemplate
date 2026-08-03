// ConsoleBackend.hpp
#pragma once
#include "Backend.hpp"
namespace CppTemplate {
class ConsoleBackend : public Backend {
public:
  void log(LogLevel level, std::string_view file, int line,
           std::string_view function, std::string_view message) override;
  void flush() override;
  void setLevel(LogLevel) override {}
};
} // namespace CppTemplate
