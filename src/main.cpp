#include <CppTemplate/explorer.hpp>
#include <CppTemplate/logger.hpp>

#include <iostream>

template<typename T>
class Span {
    T* ptr;
    std::size_t len;

public:
    template<typename Container>
    Span(Container& c)
        : ptr(c)
        , len(c.size())
    {
    }

    template<size_t N>
    Span(T (&arr)[N])
        : ptr(arr)
        , len(N)
    {
    }

    T& operator[](std::size_t pos)
    {
        return ptr[pos];
    }

    const T& operator[](std::size_t pos) const
    {
        return ptr[pos];
    }

    size_t size() const
    {
        return len;
    }
};

template<typename T>
void print(const Span<T>& span)
{
    for (std::size_t i = 0; i < span.size(); ++i) {
        LOG_INFO("{}", span[i]);
    }
}

template<typename T>
void changeOne(Span<T>& span)
{
    for (std::size_t i = 0; i < span.size(); ++i) {
        span[i] += 1;
    }
}

auto main() -> int
{
    int numbers[5] = {1, 2, 3, 4, 5};
    Span<int> span(numbers);

    LOG_INFO("Before:");
    print(span);

    changeOne(span);

    LOG_INFO("After:");
    print(span);
    // Explorer explorer;
    // explorer.run();
    return 0;
}