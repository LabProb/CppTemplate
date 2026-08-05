cmake_minimum_required(VERSION 3.20)

project(
    CppTemplate
    VERSION 0.1.0
    DESCRIPTION "Modern C++ project template"
    LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(StandardProjectSettings)
include(CompilerWarnings)
include(Coverage)
include(Sanitizers)
include(StaticAnalyzers)
include(ProjectOptions)
include(Dependencies)

# ----------------------------------------------------------
# Library
# ----------------------------------------------------------

add_library(
    CppTemplate
    STATIC
        src/explorer.cpp
        src/logger/Logger.cpp
        src/logger/ConsoleBackend.cpp
        src/logger/SpdlogBackend.cpp
        src/profiler/ScopedTimer.cpp
)

target_include_directories(
    CppTemplate
    PUBLIC
        include
)

target_link_libraries(
    CppTemplate
    PUBLIC
        spdlog::spdlog
)
# ----------------------------------------------------------
# Application
# ----------------------------------------------------------

add_executable(
    CppTemplateApp
    src/main.cpp
)

target_link_libraries(
    CppTemplateApp
    PRIVATE
        CppTemplate
)

# ----------------------------------------------------------
# Compiler warnings
# ----------------------------------------------------------

enable_warnings(CppTemplate)
enable_warnings(CppTemplateApp)

# ----------------------------------------------------------
# Sanitizers
# ----------------------------------------------------------

enable_sanitizers(CppTemplate)
enable_sanitizers(CppTemplateApp)

# ----------------------------------------------------------
# Coverage
# ----------------------------------------------------------

enable_coverage(CppTemplate)
enable_coverage(CppTemplateApp)

# ----------------------------------------------------------
# Debug options
# ----------------------------------------------------------

foreach(target
    CppTemplate
    CppTemplateApp
)
    target_compile_options(
        ${target}
        PRIVATE
            $<$<CONFIG:Debug>:-g3>
    )
endforeach()

# ----------------------------------------------------------
# Install
# ----------------------------------------------------------

install(
    TARGETS
        CppTemplateApp
    RUNTIME DESTINATION bin
)

install(
    TARGETS
        CppTemplate
    ARCHIVE DESTINATION lib
)

install(
    DIRECTORY
        include/
    DESTINATION
        include
)

# ----------------------------------------------------------
# Tests
# ----------------------------------------------------------

enable_testing()

add_subdirectory(tests)

# ----------------------------------------------------------
# Packaging
# ----------------------------------------------------------

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})

set(CPACK_PACKAGE_VENDOR "LabProb")

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
    "Modern C++ project template"
)

set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})

set(CPACK_PACKAGE_CONTACT "you@example.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "LabProb")
set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
#
# set(CPACK_RESOURCE_FILE_LICENSE
#     "${CMAKE_SOURCE_DIR}/LICENSE"
# )

set(CPACK_GENERATOR "TGZ;DEB")

include(CPack)