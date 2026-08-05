#include <gtest/gtest.h>

#include <CppTemplate/profiler/ScopedTimer.hpp>

using CppTemplate::ScopedTimer;

TEST(ScopedTimer, CanBeCreated) {
  { ScopedTimer timer("example", __FILE__, __LINE__, __func__); }

  SUCCEED();
}
