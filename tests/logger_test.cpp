#include <gtest/gtest.h>

#include <CppTemplate/logger/Logger.hpp>

using namespace CppTemplate;

TEST(LoggerTest, Basic) {
  Logger::init();

  EXPECT_NO_THROW(
      Logger::log(LogLevel::Info, __FILE__, __LINE__, __func__, "{}", "Hello"));

  Logger::shutdown();
}