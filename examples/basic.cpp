#include <CppTemplate/logger.hpp>
#include <CppTemplate/scope.hpp>

auto main() -> int
{
    LOG_INFO("Basic example started");

    DEFER(LOG_INFO("Basic example finished"));

    return 0;
}
