#pragma once

#include "Logger.hpp"

#ifndef NDEBUG

#define LOG_TRACE(...)                                                         \
  ::CppTemplate::Logger::log(::CppTemplate::LogLevel::Trace, __FILE__,         \
                             __LINE__, __func__, __VA_ARGS__)

#define LOG_DEBUG(...)                                                         \
  ::CppTemplate::Logger::log(::CppTemplate::LogLevel::Debug, __FILE__,         \
                             __LINE__, __func__, __VA_ARGS__)

#else

#define LOG_TRACE(...)
#define LOG_DEBUG(...)

#endif

#define LOG_INFO(...)                                                          \
  ::CppTemplate::Logger::log(::CppTemplate::LogLevel::Info, __FILE__,          \
                             __LINE__, __func__, __VA_ARGS__)

#define LOG_WARN(...)                                                          \
  ::CppTemplate::Logger::log(::CppTemplate::LogLevel::Warning, __FILE__,       \
                             __LINE__, __func__, __VA_ARGS__)

#define LOG_ERROR(...)                                                         \
  ::CppTemplate::Logger::log(::CppTemplate::LogLevel::Error, __FILE__,         \
                             __LINE__, __func__, __VA_ARGS__)

#define LOG_CRITICAL(...)                                                      \
  ::CppTemplate::Logger::log(::CppTemplate::LogLevel::Critical, __FILE__,      \
                             __LINE__, __func__, __VA_ARGS__)
