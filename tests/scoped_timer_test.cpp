#include <CppTemplate/profiler/ScopedTimer.hpp>
#include <gtest/gtest.h>

using CppTemplate::ScopedTimer;

TEST(ScopedTimer, CanBeCreated)
{
    {
        ScopedTimer timer("example", __FILE__, __LINE__, __func__);
    }

    SUCCEED();
}
