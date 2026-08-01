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
)

target_include_directories(
    CppTemplate
    PUBLIC
        include
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
        CppTemplate
        CppTemplateApp
)

# ----------------------------------------------------------
# Tests
# ----------------------------------------------------------

enable_testing()

add_subdirectory(tests)
