#pragma once

#include <string>

class Explorer
{
public:
    [[nodiscard]]
    auto versionString() const -> std::string;

    auto run() const -> void;

private:
    std::string currentPath_;
};