#include <CppTemplate/explorer.hpp>
#include <CppTemplate/version.hpp>

#include <gtest/gtest.h>
#include <string>

TEST(Explorer, RunPrintsVersion) {
  Explorer explorer;

  testing::internal::CaptureStdout();

  explorer.run();

  auto output = testing::internal::GetCapturedStdout();

  EXPECT_NE(output.find(cpptemplate::Version), std::string::npos);
}