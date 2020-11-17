#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <fcntl.h>

typedef struct s_map	t_map;
typedef struct s_filler	t_filler;
typedef struct s_piece	t_piece;
typedef struct s_player	t_player;
typedef struct s_point	t_point;

struct			s_point
{
	int		x;
	int		y;
};

struct			s_player
{
	char	sign;
	t_point	start;
};

struct			s_piece
{
	char	**piece;
	t_point	top; //координата начала расположения фигуры в исходом писе
	t_point	left;
	t_point	left_top;
	t_point	right_bottom;
	t_point	bottom;
	t_point	right;
	t_point	place;
	int		w;
	int		h;
	int		real_w;
	int		real_h;
};

struct				s_map
{
	unsigned char	**map;
	int				w;
	int				h;
};

struct			s_filler
{
	t_player	me;
	t_player	he;
	t_map		map;
	t_piece		piece;
};


void			set_w_h(int *w, int *h, char *line);

int				parse_player(t_filler *filler);
int				filler_loop(t_filler *filler);
int				parse_w_h(t_filler *filler, char *line);
int				parse_map(t_filler *filler, char *line);
void			clean_two_dim(void ***arr);
int				map_init(t_filler *filler);
int				emergency_clean(int last, unsigned char ***arr);
int				piece_init(t_filler *filler);
int				parse_piece(t_filler *filler, char *line);
int				solution(t_filler *filler);
int				heatmap(t_filler *filler);

t_point			point_init(int x, int y);
void			cut_figure(t_filler *filler);
int				find_min(t_filler *filler, int w, int h, t_point *res);
int				to_file(t_filler *filler);
#endif
