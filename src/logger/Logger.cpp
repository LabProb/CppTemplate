// Logger.cpp
#include <CppTemplate/logger/Logger.hpp>
#include <CppTemplate/logger/SpdlogBackend.hpp>

namespace CppTemplate {

std::unique_ptr<Backend> Logger::backend_ = nullptr;
std::mutex Logger::backendMutex_;

void Logger::init()
{
    init(LoggerConfig{}); // use defaults
}

void Logger::init(const LoggerConfig& config)
{
    std::lock_guard lock(backendMutex_);

    backend_.reset();
    backend_ = std::make_unique<SpdlogBackend>(config);
    backend_->setLevel(config.level);
}

void Logger::shutdown()
{
    std::lock_guard lock(backendMutex_);

    if (backend_) {
        backend_->flush();
        backend_.reset();
    }
}

void Logger::setLevel(LogLevel level)
{
    std::lock_guard lock(backendMutex_);

    if (backend_) {
        backend_->setLevel(level);
    }
}

void Logger::logMessage(
    LogLevel level,
    std::string_view file,
    int line,
    std::string_view function,
    std::string_view message)
{
    std::lock_guard lock(backendMutex_);

    if (!backend_) {
        backend_ = std::make_unique<SpdlogBackend>(LoggerConfig{});
    }
    backend_->log(level, file, line, function, message);
}

} // namespace CppTemplate
