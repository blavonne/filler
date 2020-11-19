cmake_minimum_required(VERSION 3.17)
project(libdraw C)

set(CMAKE_C_STANDARD 99)
include_directories(includes)
include_directories(minilibx)
add_library(libdraw complex_math.c complex_trig.c
        draw_line.c mlx_color.c mlx_create.c ./includes/graphics_base.h
        ./includes/keyboard.h ./includes/colors.h point_handler.c put_images.c)