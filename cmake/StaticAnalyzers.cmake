find_program(CLANG_TIDY_EXE clang-tidy)
find_program(RUN_CLANG_TIDY_EXE run-clang-tidy)

if(CLANG_TIDY_EXE)
    message(STATUS "clang-tidy: ${CLANG_TIDY_EXE}")
endif()

if(RUN_CLANG_TIDY_EXE)

    message(STATUS "run-clang-tidy: ${RUN_CLANG_TIDY_EXE}")

    set(
        CLANG_TIDY_HEADER_FILTER
        "^${PROJECT_SOURCE_DIR}/(include|src)"
    )

    add_custom_target(

        tidy

        COMMAND
            ${RUN_CLANG_TIDY_EXE}
            -p
            ${CMAKE_BINARY_DIR}
            "-header-filter=${CLANG_TIDY_HEADER_FILTER}"

        WORKING_DIRECTORY
            ${PROJECT_SOURCE_DIR}

        COMMENT
            "Running clang-tidy"

        VERBATIM

    )

endif()