include(FetchContent)

# ----------------------------------------------------------
# GoogleTest
# ----------------------------------------------------------

set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# ----------------------------------------------------------
# spdlog
# ----------------------------------------------------------

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.15.3
)

# ----------------------------------------------------------
# Download dependencies
# ----------------------------------------------------------

FetchContent_MakeAvailable(
    googletest
    spdlog
)