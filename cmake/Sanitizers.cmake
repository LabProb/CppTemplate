function(enable_sanitizers TARGET)

    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

        set(SANITIZER_FLAGS
            -fsanitize=address
            -fsanitize=undefined
            -fno-omit-frame-pointer
        )

        target_compile_options(
            ${TARGET}
            PRIVATE
                $<$<CONFIG:Debug>:${SANITIZER_FLAGS}>
        )

        target_link_options(
            ${TARGET}
            PRIVATE
                $<$<CONFIG:Debug>:${SANITIZER_FLAGS}>
        )

    endif()

endfunction()
