#include <CppTemplate/logger/LogMacros.hpp>
#include <CppTemplate/profiler/ScopedTimer.hpp>

namespace CppTemplate {

ScopedTimer::ScopedTimer(std::string_view name, std::string_view file, int line,
                         std::string_view function)
    : name_(name), start_(std::chrono::steady_clock::now()), file_(file),
      line_(line), function_(function) {}

ScopedTimer::~ScopedTimer() noexcept {
  try {
    const auto end = std::chrono::steady_clock::now();
    const auto elapsed = end - start_;

    if (elapsed < std::chrono::milliseconds{1}) {
      LOG_DEBUG("[Timer] {:<30} {:>6} us", name_,
                std::chrono::duration_cast<std::chrono::microseconds>(elapsed)
                    .count());
    } else if (elapsed < std::chrono::seconds{1}) {
      LOG_DEBUG("[Timer] {:<30} {:>6} ms", name_,
                std::chrono::duration_cast<std::chrono::milliseconds>(elapsed)
                    .count());
    } else {
      LOG_DEBUG("[Timer] {:<30} {:>8.3f} s", name_,
                std::chrono::duration<double>(elapsed).count());
    }
  } catch (...) {
    // Never throw from a destructor.
  }
}

} // namespace CppTemplate
