#include <CppTemplate/logger/Logger.hpp>
#include <gtest/gtest.h>

using namespace CppTemplate;

TEST(LoggerTest, Basic)
{
    Logger::init();

    EXPECT_NO_THROW(Logger::log(LogLevel::Info, __FILE__, __LINE__, __func__, "{}", "Hello"));

    Logger::shutdown();
}