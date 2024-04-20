cmake_minimum_required(VERSION 3.28)
project(cpp_playground)

set(CMAKE_CXX_STANDARD 26)

include(FetchContent)
FetchContent_Declare(Catch2 GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG devel)
FetchContent_MakeAvailable(Catch2)

file(GLOB SOURCES "src/*.cpp")
file(GLOB TESTS "test/*.cpp")

add_library(src_lib ${SOURCES})

add_executable(unit_tests_bin ${TESTS})
target_link_libraries(unit_tests_bin PRIVATE src_lib Catch2::Catch2WithMain)
enable_testing()
add_test(NAME test COMMAND unit_tests_bin)
