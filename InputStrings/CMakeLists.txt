cmake_minimum_required(VERSION 3.17)
project(strings)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)
set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(strings
        main.cpp)
