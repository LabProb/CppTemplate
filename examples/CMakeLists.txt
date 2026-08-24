add_executable(
    CppTemplateBasicExample
    basic.cpp
)

target_link_libraries(
    CppTemplateBasicExample
    PRIVATE
        CppTemplate
)

enable_warnings(CppTemplateBasicExample)
enable_sanitizers(CppTemplateBasicExample)
enable_coverage(CppTemplateBasicExample)
