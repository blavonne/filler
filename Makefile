NAME = blavonne.filler
#BASE---------------------------------------------------------------------------
SRC_DIR = ./srcs/
INC_DIR = ./includes/
#LIBFT--------------------------------------------------------------------------
LIBFT = ./libft/libft.a
L_ROOT = ./libft/
L_LIB = -L $(L_ROOT) -lft
#FLAGS--------------------------------------------------------------------------
FLAGS = -Wall -Werror -Wextra
#SOURCES------------------------------------------------------------------------
SRC = main.c\
	$(SRC_DIR)cleaner.c\
	$(SRC_DIR)figure_handler.c\
	$(SRC_DIR)figure_place.c\
	$(SRC_DIR)filler_loop.c\
	$(SRC_DIR)heatmap.c\
	$(SRC_DIR)parse_map.c\
	$(SRC_DIR)parse_piece.c\
	$(SRC_DIR)parse_player.c\
	$(SRC_DIR)point_handler.c\
	$(SRC_DIR)solution.c
OBJ = $(SRC:%.c=%.o)
#HEADERS------------------------------------------------------------------------
HEADERS = -I $(INC_DIR) -I $(L_ROOT)
#builder------------------------------------------------------------------------
all: $(NAME)
-include $(OBJ:.o=.d)
# build external libraries------------------------------------------------------
$(LIBFT): make_libft
make_libft:
	$(MAKE) -C $(L_ROOT)
# build filler------------------------------------------------------------------
$(NAME): $(OBJ) $(LIBFT)
	gcc -o $(NAME) $(OBJ) $(HEADERS) $(FLAGS) $(L_LIB)
%.o: %.c $(LIBFT)
	gcc -c $< -o $@ $(HEADERS) $(FLAGS) -MMD
# clean section-----------------------------------------------------------------
clean:
	$(MAKE) -C $(L_ROOT) clean
	rm -rf $(OBJ)
	rm -rf $(OBJ:.o=.d)
fclean: clean
	$(MAKE) -C $(L_ROOT) fclean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re make_libft
