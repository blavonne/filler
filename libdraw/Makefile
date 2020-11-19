NAME = libdraw.a
INC_DIR = ./includes/
SRC = complex_math.c\
	complex_trig.c\
	draw_line.c\
	mlx_color.c\
	mlx_create.c\
	point_handler.c\
	put_images.c\
	ft_swap.c

OBJ = $(SRC:%.c=%.o)
HEADERS = -I $(INC_DIR) -I $(MLX_ROOT)
#MLX&FLAGS----------------------------------------------------------------------
CUR_OS = $(shell sh -c 'uname 2>/dev/null || echo Unknown')
ifeq ($(CUR_OS), Darwin)
	MLX = ./minilibx_mac/libmlx.a
	MLX_ROOT = ./minilibx_mac/
	MLX_LIB = -L $(MLX_ROOT) -lmlx
	LIBS = -framework OpenGl -framework Appkit
	FLAGS = -Wall -Werror -Wextra
else
	MLX = ./minilibx/libmlx.a
	MLX_ROOT = ./minilibx/
	MLX_LIB = -L $(MLX_ROOT) -lmlx
	LIBS = -lX11 -lXext -lm
	FLAGS = -Wall -Werror -Wextra -fsanitize=leak
endif
# builder-----------------------------------------------------------------------
all: $(MLX) $(NAME)
-include $(OBJ:.o=.d)
# build external libraries------------------------------------------------------
$(MLX): make_mlx
make_mlx:
	$(MAKE) -C $(MLX_ROOT)
#-------------------------------------------------------------------------------
$(NAME): $(OBJ)
	cp $(MLX) ./$(NAME)
	ar rcs $(NAME) $(OBJ)
%.o: %.c
	gcc -c $< -o $@ $(HEADERS) $(FLAGS) -MMD
# clean section-----------------------------------------------------------------
clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(MLX_ROOT) clean
	rm -rf $(OBJ:.o=.d)
fclean: clean
	$(MAKE) -C $(MLX_ROOT) fclean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re