function(enable_coverage TARGET)

    if(NOT ENABLE_COVERAGE)
        return()
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

        target_compile_options(
            ${TARGET}
            PRIVATE
                --coverage
                -O0
                -g
        )

        target_link_options(
            ${TARGET}
            PRIVATE
                --coverage
        )

    endif()

endfunction()
