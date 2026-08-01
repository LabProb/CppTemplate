#include <gtest/gtest.h>

#include <CppTemplate/version.hpp>

TEST(Version, IsCorrect) { EXPECT_EQ(cpptemplate::Version, "0.1.0"); }