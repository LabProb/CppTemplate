#include <CppTemplate/explorer.hpp>
#include <CppTemplate/logger.hpp>
#include <CppTemplate/version.hpp>

#include <iostream>

auto Explorer::versionString() const -> std::string {
  return currentPath_ + " " + cpptemplate::Version;
}

auto Explorer::run() const -> void { LOG_INFO("Version: {}", versionString()); }
