#pragma once

#include "ScopeGuard.hpp"

#define CONCAT_IMPL(x, y) x##y
#define CONCAT(x, y) CONCAT_IMPL(x, y)

#define DEFER(...)                                                             \
  auto CONCAT(scopeGuard_, __LINE__) =                                         \
      ::CppTemplate::makeScopeGuard([&]() { __VA_ARGS__; })
