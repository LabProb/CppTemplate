#include <CppTemplate/explorer.hpp>
#include <CppTemplate/logger.hpp>
#include <CppTemplate/profiler.hpp>
#include <CppTemplate/version.hpp>

#include <thread>

auto Explorer::versionString() const -> std::string {
  return currentPath_ + " " + cpptemplate::Version;
}

auto Explorer::run() const -> void {
  SCOPED_FUNCTION_TIMER();

  CppTemplate::Stopwatch sw;

  sw.start();

  sw.start();
  std::this_thread::sleep_for(std::chrono::milliseconds(20));
  sw.stop();

  LOG_INFO("{} ms", sw.elapsedMilliseconds());

  sw.start();
  std::this_thread::sleep_for(std::chrono::milliseconds(30));
  sw.stop();

  sw.reset();
  sw.start();
  LOG_INFO("{} ms", sw.elapsedMilliseconds());

  LOG_INFO("Version: {}", versionString());
  LOG_WARN("Version: {}", versionString());
  LOG_DEBUG("Version: {}", versionString());

  std::this_thread::sleep_for(std::chrono::milliseconds(50));

  LOG_INFO("Stopwatch: {} us", sw.elapsedMicroseconds());
  LOG_INFO("Stopwatch: {} ms", sw.elapsedMilliseconds());
  LOG_INFO("Stopwatch: {:.3f} s", sw.elapsedSeconds());
  sw.stop();
}