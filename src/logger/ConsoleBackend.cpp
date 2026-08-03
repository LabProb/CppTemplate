// ConsoleBackend.cpp
#include <CppTemplate/logger/ConsoleBackend.hpp>
#include <iostream>
namespace CppTemplate {
void ConsoleBackend::log(LogLevel /*level*/, std::string_view file, int line,
                         std::string_view function, std::string_view message) {
  std::cout << file << ':' << line << ' ' << function << " -> " << message
            << std::endl;
}
void ConsoleBackend::flush() { std::cout.flush(); }
} // namespace CppTemplate
