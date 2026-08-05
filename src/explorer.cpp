#include <CppTemplate/explorer.hpp>
#include <CppTemplate/logger.hpp>
#include <CppTemplate/profiler.hpp>
#include <CppTemplate/version.hpp>

#include <iostream>

auto Explorer::versionString() const -> std::string {
  return currentPath_ + " " + cpptemplate::Version;
}

auto Explorer::run() const -> void {
  SCOPED_FUNCTION_TIMER();
  LOG_INFO("Version: {}", versionString());
  LOG_WARN("Version: {}", versionString());
  LOG_DEBUG("Version: {}", versionString());
}
