cmake_minimum_required(VERSION 3.17)
project(strings)
set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(strings
        main.cpp)
target_compile_options(strings PRIVATE -Wall -Wextra -Wpedantic -Werror)
