#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <fcntl.h> //del

typedef struct s_map	t_map;
typedef struct s_filler	t_filler;
typedef struct s_piece	t_piece;
typedef struct s_player	t_player;
typedef struct s_point	t_point;

struct				s_point
{
	int				x;
	int				y;
};

struct				s_player
{
	char			sign;
};

/*
** top, left, bottom, right are coordinates of figure's begin on piece-map
** (eqv cutting)
** place is calculated place to put figure
** real_h is physical height of figure
*/

struct				s_piece
{
	char			**piece;
	t_point			place;
	int				top;
	int				left;
	int				bottom;
	int				right;
	int				w;
	int				h;
	int				real_h;
};

struct				s_map
{
	unsigned char	**map;
	int				w;
	int				h;
};

struct				s_filler
{
	t_player		me;
	t_player		he;
	t_map			map;
	t_piece			piece;
};


int					parse_player(t_filler *filler);
int					filler_loop(t_filler *filler);
int					parse_w_h(t_filler *filler, char *line);
int					parse_map(t_filler *filler, char *line);
void				clean_two_dim(void ***arr);
int					map_init(t_filler *filler);
int					emergency_clean(int last, unsigned char ***arr);
int					piece_init(t_filler *filler);
int					parse_piece(t_filler *filler, char *line);
int					solution(t_filler *filler);
int					heatmap(t_filler *filler);
t_point				point_init(int x, int y);
void				cut_figure(t_filler *filler);
int					find_min(t_filler *filler, int w, int h);
int					to_file(t_filler *filler);
void				heat_to_file(t_filler *filler);
#endif
