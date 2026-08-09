#pragma once

#include "LogLevel.hpp"

#include <string_view>

namespace CppTemplate {

class Backend {
public:
    virtual ~Backend() = default;

    virtual void
    log(LogLevel level,
        std::string_view file,
        int line,
        std::string_view function,
        std::string_view message)
        = 0;

    virtual void flush() = 0;
    virtual void setLevel(LogLevel level) = 0;
};

} // namespace CppTemplate
