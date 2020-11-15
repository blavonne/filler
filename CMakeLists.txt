cmake_minimum_required(VERSION 3.17)
project(filler C)

set(CMAKE_C_STANDARD 99)
include_directories(libft)
add_subdirectory(libft)

add_executable(filler main.c)
target_link_libraries(filler libft)