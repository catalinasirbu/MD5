cmake_minimum_required(VERSION 3.14)

SET(CMAKE_C_COMPILER C:\\\\cygwin64\\\\bin\\\\gcc)
SET(CMAKE_CXX_COMPILER C:\\\\cygwin64\\\\bin\\\\g++)

project(md5)
message(${CMAKE_SOURCE_DIR})

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(executabil ${CMAKE_SOURCE_DIR}/iesire/UT_1.cpp)

target_link_libraries(executabil GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(executabil)