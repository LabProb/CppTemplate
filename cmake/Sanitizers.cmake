function(enable_sanitizers TARGET)

    if(CMAKE_BUILD_TYPE STREQUAL "Debug")

        if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

            target_compile_options(
                ${TARGET}
                PRIVATE
                    -fsanitize=address
                    -fsanitize=undefined
            )

            target_link_options(
                ${TARGET}
                PRIVATE
                    -fsanitize=address
                    -fsanitize=undefined
            )

        endif()

    endif()

endfunction()