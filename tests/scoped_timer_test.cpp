#include <CppTemplate/profiler/ScopedTimer.hpp>
#include <CppTemplate/scope/ScopeGuard.hpp>
#include <gtest/gtest.h>

#include <utility>

using CppTemplate::ScopedTimer;

TEST(ScopedTimer, CanBeCreated)
{
    {
        ScopedTimer timer("example", __FILE__, __LINE__, __func__);
    }

    SUCCEED();
}

TEST(ScopeGuard, InvokesFunctionAtScopeExit)
{
    bool invoked = false;

    {
        auto guard = CppTemplate::makeScopeGuard([&]() { invoked = true; });
    }

    EXPECT_TRUE(invoked);
}

TEST(ScopeGuard, CanBeDismissed)
{
    bool invoked = false;

    {
        auto guard = CppTemplate::makeScopeGuard([&]() { invoked = true; });
        guard.dismiss();
    }

    EXPECT_FALSE(invoked);
}

TEST(ScopeGuard, TransfersCleanupWhenMoved)
{
    int invocations = 0;

    {
        auto first = CppTemplate::makeScopeGuard([&]() { ++invocations; });
        auto second = std::move(first);
    }

    EXPECT_EQ(invocations, 1);
}

TEST(ScopeGuard, SwallowsExceptionsFromCleanup)
{
    EXPECT_NO_THROW({ auto guard = CppTemplate::makeScopeGuard([]() { throw 1; }); });
}
