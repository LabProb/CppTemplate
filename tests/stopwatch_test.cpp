#include <gtest/gtest.h>

#include <CppTemplate/profiler/Stopwatch.hpp>

using CppTemplate::Stopwatch;

TEST(Stopwatch, IsNotRunningAfterConstruction) {
  Stopwatch sw;

  EXPECT_FALSE(sw.isRunning());
}
TEST(Stopwatch, StartChangesRunningState) {
  Stopwatch sw;

  sw.start();

  EXPECT_TRUE(sw.isRunning());
}
TEST(Stopwatch, StopChangesRunningState) {
  Stopwatch sw;

  sw.start();
  sw.stop();

  EXPECT_FALSE(sw.isRunning());
}
#include <thread>

TEST(Stopwatch, MeasuresElapsedTime) {
  Stopwatch sw;

  sw.start();

  std::this_thread::sleep_for(std::chrono::milliseconds(20));

  sw.stop();

  EXPECT_GE(sw.elapsedMilliseconds(), 20);
}
TEST(Stopwatch, ResetClearsElapsedTime) {
  Stopwatch sw;

  sw.start();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  sw.stop();

  sw.reset();

  EXPECT_EQ(sw.elapsedMilliseconds(), 0);
  EXPECT_FALSE(sw.isRunning());
}