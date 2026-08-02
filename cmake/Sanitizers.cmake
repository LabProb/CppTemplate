function(enable_sanitizers TARGET)

    if(NOT ENABLE_SANITIZERS)
        return()
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

        target_compile_options(
            ${TARGET}
            PRIVATE
                -fsanitize=address
                -fsanitize=undefined
                -fno-omit-frame-pointer
        )

        target_link_options(
            ${TARGET}
            PRIVATE
                -fsanitize=address
                -fsanitize=undefined
                -fno-omit-frame-pointer
        )

    endif()

endfunction()