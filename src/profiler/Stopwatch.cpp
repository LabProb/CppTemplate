#include <CppTemplate/profiler/Stopwatch.hpp>

namespace CppTemplate {

auto Stopwatch::elapsed() const noexcept
    -> std::chrono::steady_clock::duration {
  if (running_) {
    return elapsed_ + (std::chrono::steady_clock::now() - start_);
  }

  return elapsed_;
}

auto Stopwatch::elapsedNanoseconds() const noexcept -> std::uint64_t {
  return std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed())
      .count();
}

auto Stopwatch::elapsedMicroseconds() const noexcept -> std::uint64_t {
  return std::chrono::duration_cast<std::chrono::microseconds>(elapsed())
      .count();
}

auto Stopwatch::elapsedMilliseconds() const noexcept -> std::uint64_t {
  return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed())
      .count();
}

auto Stopwatch::elapsedSeconds() const noexcept -> double {
  return std::chrono::duration<double>(elapsed()).count();
}

void Stopwatch::start() noexcept {
  if (!running_) {
    start_ = std::chrono::steady_clock::now();
    running_ = true;
  }
}

void Stopwatch::stop() noexcept {
  if (running_) {
    elapsed_ += std::chrono::steady_clock::now() - start_;
    running_ = false;
  }
}

void Stopwatch::reset() noexcept {
  elapsed_ = {};
  start_ = {};
  running_ = false;
}
} // namespace CppTemplate