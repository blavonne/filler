/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "graphics_base.h"

/*
** forbidden functions: exit (for mlx), delay() for beautiful draw
** maybe something from math.h (allow in all graphics projects)
*/

typedef struct s_map	t_map;
typedef struct s_filler	t_filler;
typedef struct s_piece	t_piece;
typedef struct s_player	t_player;

struct				s_player
{
	char			sign;
};

/*
** top, left, bottom, right are coordinates of figure's begin on piece-map
** (eqv cutting)
** place is calculated place to put figure
** real_h is physical height of figure
** cross is condition when piece overlaps map
** w and h are original w and h of figure with all dots '.'
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
	int				cross;
};

/*
** unsigned char: cause the biggest map is 100x100 and the worst distance
** between (0;0) and (99;98) is max((|0 - 99|), (|0 - 98|)) = 99
** first 32 non-printable symbols we skip, so we should keep range
** from 32 to (99 + 32 + 3) = 131 (this 3 symbols are '.', 'O' and 'X')
** if we want to print heatmap to debug;
** unsigned char range is between 0 and 255 so it fits good to our goal
** and we can use no int[][]
*/

struct				s_map
{
	char			**map;
	char			**heat;
	int				w;
	int				h;
};

/*
** win_w, win_h are size of window
** square_len is len of square's side for draw (scale)
** margin is actually padding :))) pixels between squares
** draw is flag that means to draw ot not to draw
** delay is for usleep (value in ms to wait between operations)
*/

struct				s_filler
{
	t_mlx			mlx;
	t_player		me;
	t_player		he;
	t_map			map;
	t_piece			piece;
	int				win_w;
	int				win_h;
	int				square_len;
	int				margin;
	int				draw;
	int				delay;
};

int					parse_player(t_filler *filler);
int					parse_w_h(t_filler *filler, char *line);
int					parse_map(t_filler *filler, char *line);
int					parse_piece(t_filler *filler, char *line);
int					map_init(t_filler *filler);
int					piece_init(t_filler *filler);

void				clean_two_dim(void ***arr);
int					emergency_clean(int last, char ***arr);
void				clean_mlx(t_mlx *mlx);
int					clean_exit(t_filler *filler);

int					mlx_filler_loop(t_filler *filler);
int					filler_loop(t_filler *filler);
int					filler_draw(t_filler *filler);
int					solution(t_filler *filler);
int					heatmap(t_filler *filler, char find, char replace);
void				clear_heatmap(t_filler *filler);
void				cut_figure(t_filler *filler);
int					find_min(t_filler *filler, int w, int h);

int					deal_key(int key, t_filler *filler);

#endif
