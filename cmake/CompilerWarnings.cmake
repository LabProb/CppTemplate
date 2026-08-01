# ----------------------------------------------------------
# Compiler warnings
# ----------------------------------------------------------
function(enable_warnings TARGET)

    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

        target_compile_options(
            ${TARGET}
            PRIVATE
                -Wall
                -Wextra
                -Wpedantic
                -Wconversion
                -Wshadow
        )

    endif()

endfunction()