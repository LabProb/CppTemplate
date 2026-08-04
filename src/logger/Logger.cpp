// Logger.cpp
#include <CppTemplate/logger/ConsoleBackend.hpp>
#include <CppTemplate/logger/Logger.hpp>
#include <CppTemplate/logger/SpdlogBackend.hpp>

namespace CppTemplate {

std::unique_ptr<Backend> Logger::backend_ = nullptr;

void Logger::init() {
  init(LoggerConfig{}); // use defaults
}

void Logger::init(const LoggerConfig &config) {
  // (Re)initialize the backend. In practice, call shutdown() first to reset
  // state.
  backend_.reset();
  // Use the config to create a SpdlogBackend (or other) instance
  // For example:
  backend_ = std::make_unique<SpdlogBackend>(config);
  // Set the initial log level:
  backend_->setLevel(config.level);
}

void Logger::shutdown() {
  if (backend_) {
    backend_->flush();
    backend_.reset();
  }
}

void Logger::setLevel(LogLevel level) {
  if (backend_) {
    backend_->setLevel(level);
  }
}

void Logger::logMessage(LogLevel level, std::string_view file, int line,
                        std::string_view function, std::string_view message) {
  if (!backend_) {
    // Auto-init with defaults if not already inited:
    init();
  }
  // Forward to backend sink:
  backend_->log(level, file, line, function, message);
  // If immediate flush on each message is desired (could be in config):
  // backend_->flush();  // or inside the backend implementation as shown below.
}

} // namespace CppTemplate
