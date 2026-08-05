#pragma once

#include <chrono>
#include <cstdint>

namespace CppTemplate {

class Stopwatch {
public:
  void start() noexcept;
  void stop() noexcept;
  void reset() noexcept;

  [[nodiscard]]
  constexpr auto isRunning() const noexcept -> bool {
    return running_;
  }
  [[nodiscard]]
  auto elapsed() const noexcept -> std::chrono::steady_clock::duration;

  [[nodiscard]]
  auto elapsedNanoseconds() const noexcept -> std::uint64_t;
  [[nodiscard]]
  auto elapsedMicroseconds() const noexcept -> std::uint64_t;
  [[nodiscard]]
  auto elapsedMilliseconds() const noexcept -> std::uint64_t;
  [[nodiscard]]
  auto elapsedSeconds() const noexcept -> double;

private:
  std::chrono::steady_clock::time_point start_{};
  std::chrono::steady_clock::duration elapsed_{};

  bool running_{false};
};

} // namespace CppTemplate