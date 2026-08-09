#include <CppTemplate/version.hpp>
#include <gtest/gtest.h>

TEST(Version, IsCorrect)
{
    EXPECT_EQ(cpptemplate::Version, "0.1.0");
}