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
include(Sanitizers)
include(StaticAnalyzers)
include(ProjectOptions)
include(Dependencies)

# ----------------------------------------------------------
# Executable
# ----------------------------------------------------------

add_executable(
    CppTemplateApp
    src/main.cpp
)

add_library(CppTemplate STATIC src/explorer.cpp)

target_include_directories(
    CppTemplate
    PUBLIC
        include
)

# ----------------------------------------------------------
# Compiler warnings
# ----------------------------------------------------------

enable_warnings(CppTemplate)
enable_warnings(CppTemplateApp)

# ----------------------------------------------------------
# Debug options
# ----------------------------------------------------------

target_compile_options(
    CppTemplate
    PRIVATE
        $<$<CONFIG:Debug>:-g3>
)

target_compile_options(
    CppTemplateApp
    PRIVATE
        $<$<CONFIG:Debug>:-g3>
)

# ----------------------------------------------------------
# Install
# ----------------------------------------------------------

install(
    TARGETS CppTemplate CppTemplateApp
)

# ----------------------------------------------------------
# Tests
# ----------------------------------------------------------

enable_testing()

add_subdirectory(tests)

target_link_libraries(CppTemplateApp PRIVATE CppTemplate)