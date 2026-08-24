#pragma once

#include <type_traits>
#include <utility>

namespace CppTemplate {

template<typename F>
class ScopeGuard {
public:
    explicit ScopeGuard(F&& func)
        : function_(std::forward<F>(func))
    {
    }

    ~ScopeGuard() noexcept
    {
        if (active_) {
            try {
                function_();
            } catch (...) {
                // Destructors must not throw during stack unwinding.
            }
        }
    }

    ScopeGuard(const ScopeGuard&) = delete;
    ScopeGuard& operator=(const ScopeGuard&) = delete;

    ScopeGuard(ScopeGuard&& other) noexcept(std::is_nothrow_move_constructible_v<F>)
        : function_(std::move(other.function_))
        , active_(other.active_)
    {
        other.dismiss();
    }

    ScopeGuard& operator=(ScopeGuard&&) = delete;

    void dismiss() noexcept
    {
        active_ = false;
    }

private:
    F function_;
    bool active_{true};
};

template<typename F>
[[nodiscard]]
auto makeScopeGuard(F&& func)
{
    return ScopeGuard<std::decay_t<F>>(std::forward<F>(func));
}

} // namespace CppTemplate
