cmake_minimum_required(VERSION 3.17)
project(filler C)

set(CMAKE_C_STANDARD 99)
include_directories(libft)
include_directories(includes)
add_subdirectory(libft)

add_executable(filler main.c srcs/parse_player.c srcs/cleaner.c srcs/filler_loop.c srcs/parse_map.c srcs/parse_piece.c srcs/solution.c)
target_link_libraries(filler libft)