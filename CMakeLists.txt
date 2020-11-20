cmake_minimum_required(VERSION 3.17)
project(filler C)

set(CMAKE_C_STANDARD 99)
include_directories(libft)
include_directories(includes)
include_directories(./libdraw/includes)
add_subdirectory(libft)
add_subdirectory(libdraw)
add_executable(filler main.c srcs/parse_player.c srcs/cleaner.c srcs/filler_loop.c srcs/parse_map.c srcs/parse_piece.c srcs/solution.c srcs/heatmap.c srcs/figure_handler.c srcs/figure_place.c srcs/filler_draw.c srcs/mlx_filler_loop.c srcs/keyboard.c)
target_link_libraries(filler libft libdraw -lm -lX11 -lXext
        /home/blavonne/CLionProjects/filler/libdraw/libdraw.a)