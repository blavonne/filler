NAME = blavonne.filler
#BASE---------------------------------------------------------------------------
SRC_DIR = ./srcs/
INC_DIR = ./includes/
#LIBFT--------------------------------------------------------------------------
LIBFT = ./libft/libft.a
L_ROOT = ./libft/
L_LIB = -L $(L_ROOT) -lft
#MLX&FLAGS----------------------------------------------------------------------
CUR_OS = $(shell sh -c 'uname 2>/dev/null || echo Unknown')
ifeq ($(CUR_OS), Darwin)
	MLX_ROOT = ./libdraw/minilibx_mac/
	LIBS = -framework OpenGl -framework Appkit
	FLAGS = -Wall -Werror -Wextra
else
	MLX_ROOT = ./libdraw/minilibx/
	LIBS = -lX11 -lXext -lm
	FLAGS = -Wall -Werror -Wextra -fsanitize=leak
endif
#libdraw------------------------------------------------------------------------
DRAW = ./libdraw/libdraw.a
D_ROOT = ./libdraw/
D_LIB = -L $(D_ROOT) -ldraw
D_INC = ./libdraw/includes/
#SOURCES------------------------------------------------------------------------
SRC = main.c\
	$(SRC_DIR)cleaner.c\
	$(SRC_DIR)keyboard.c\
	$(SRC_DIR)figure_handler.c\
	$(SRC_DIR)figure_place.c\
	$(SRC_DIR)filler_loop.c\
	$(SRC_DIR)heatmap.c\
	$(SRC_DIR)parse_map.c\
	$(SRC_DIR)parse_piece.c\
	$(SRC_DIR)parse_player.c\
	$(SRC_DIR)solution.c\
	$(SRC_DIR)to_file.c\
	$(SRC_DIR)filler_draw.c\
	$(SRC_DIR)mlx_filler_loop.c
OBJ = $(SRC:%.c=%.o)
#HEADERS------------------------------------------------------------------------
HEADERS = -I $(INC_DIR) -I $(L_ROOT) -I $(MLX_ROOT) -I $(D_INC)
#builder------------------------------------------------------------------------
all: $(NAME)
-include $(OBJ:.o=.d)
# build external libraries------------------------------------------------------
$(LIBFT): make_libft
make_libft:
	$(MAKE) -C $(L_ROOT)
$(DRAW): make_draw
make_draw:
	$(MAKE) -C $(D_ROOT)
# build filler------------------------------------------------------------------
$(NAME): $(OBJ) $(LIBFT) $(MLX) $(DRAW)
	gcc -o $(NAME) $(OBJ) $(HEADERS) $(FLAGS) $(L_LIB) $(D_LIB) $(LIBS)
%.o: %.c $(LIBFT) $(MLX) $(DRAW)
	gcc -c $< -o $@ $(HEADERS) $(FLAGS) -MMD
# clean section-----------------------------------------------------------------
clean:
	$(MAKE) -C $(L_ROOT) clean
	$(MAKE) -C $(D_ROOT) clean
	rm -rf $(OBJ)
	rm -rf $(OBJ:.o=.d)
fclean: clean
	$(MAKE) -C $(L_ROOT) fclean
	$(MAKE) -C $(D_ROOT) fclean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re make_libft
