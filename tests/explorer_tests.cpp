#include <CppTemplate/explorer.hpp>
#include <CppTemplate/version.hpp>

#include <gtest/gtest.h>

TEST(Explorer, VersionStringContainsVersion) {
  Explorer explorer;

  EXPECT_NE(explorer.versionString().find(cpptemplate::Version),
            std::string::npos);
}