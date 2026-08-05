#pragma once

#include "ScopedTimer.hpp"

#define SCOPED_TIMER(name)                                                     \
  ::CppTemplate::ScopedTimer scopedTimer##__LINE__(name, __FILE__, __LINE__,   \
                                                   __func__)

#define SCOPED_FUNCTION_TIMER()                                                \
  ::CppTemplate::ScopedTimer scopedTimer##__LINE__(                            \
      __PRETTY_FUNCTION__, __FILE__, __LINE__, __func__)
