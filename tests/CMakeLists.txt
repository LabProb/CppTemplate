add_executable(
    CppTemplateTests
    main.cpp
    version_test.cpp
     explorer_tests.cpp
)

target_link_libraries(
    CppTemplateTests
    PRIVATE
        CppTemplate
        GTest::gtest
        GTest::gtest_main
)

target_include_directories(
    CppTemplateTests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

include(GoogleTest)

gtest_discover_tests(CppTemplateTests)