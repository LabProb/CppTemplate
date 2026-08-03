add_executable(
    CppTemplateTests
    main_test.cpp
    version_test.cpp
    explorer_test.cpp
    logger_test.cpp
)

target_link_libraries(
    CppTemplateTests
    PRIVATE
        CppTemplate
        GTest::gtest_main
)

enable_warnings(CppTemplateTests)
enable_sanitizers(CppTemplateTests)
enable_coverage(CppTemplateTests)

target_compile_options(
    CppTemplateTests
    PRIVATE
        $<$<CONFIG:Debug>:-g3>
)

include(GoogleTest)

gtest_discover_tests(CppTemplateTests)
