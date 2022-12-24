cmake_minimum_required(VERSION 3.23)

project(heartbeat_project CXX C)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wextra")

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG         release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set (INCLUDE_DIR 
../src
.
)

include_directories(${INCLUDE_DIR})

add_executable(
    ${CMAKE_PROJECT_NAME}
    ../src/heartbeat.c
)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    gmock
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME})