#include "filler.h"

void		start_from(int *y, t_filler *filler)
{
	int		h;
	int		w;

	h = 0;
	while (h < filler->map.h)
	{
		w = 0;
		while (w < filler->map.w)
		{
			if (filler->map.map[h][w] == filler->me.sign)
			{
				*y = h - filler->piece.real_h;
				if (*y < 0)
					*y = filler->piece.real_h - 1;
				return ;
			}
			w++;
		}
		h++;
	}
}

int			find_place(t_filler *filler)
{
	int		h;
	int		w;
	int		sum;
	int		min_sum;
	t_point	res;

	h = 0;
	sum = 0;
	min_sum = filler->map.h * filler->map.w;
	res = point_init(0, 0);
	start_from(&h, filler);
	while (h < filler->map.h)
	{
		w = 0;
		while (w < filler->map.w)
		{
			sum = find_min(filler, w, h, &res);
			if (sum && sum < min_sum)
			{
				min_sum = sum;
				filler->piece.place = res;
			}
			w++;
		}
		h++;
	}
	if (sum)
		return (1);
	else
		return (0);
}

void		normalize_place(t_filler *filler)
{
	filler->piece.place.x -= filler->piece.left.x;
	filler->piece.place.y -= filler->piece.top.y;
}

/*
** ltrb means left top right bottom
*/

void		enemy_position(t_filler *filler)
{
	int		h;
	int		w;
	t_point	ltrb[2];

	h = 0;
	ft_bzero(ltrb, sizeof(t_point) * 2);
	ltrb[1] = point_init(filler->map.w - 1, filler->map.h - 1);
	while (h < filler->map.h)
	{
		w = 0;
		while (w < filler->map.w)
		{
			if (filler->map.map[h][w] == filler->he.sign)
			{
				w < ltrb[0].x ? (ltrb[0].x = w) : 0;
				w > ltrb[1].x ? (ltrb[1].x = w) : 0;
				h < ltrb[0].y ? (ltrb[0].y = h) : 0;
				h > ltrb[1].y ? (ltrb[1].y = h) : 0;
			}
			w++;
		}
		h++;
	}
	filler->he.right_bottom = ltrb[1];
	filler->he.left_top = ltrb[0];
}

void		set_priority(t_filler *filler, char type)
{
	if (!ft_memcmp(&filler->he.left_top, &filler->he.right_bottom,\
	sizeof(t_point)))
		filler->he.priority = filler->he.left_top;
	else
	{
		if (type)
		{
			filler->he.lt_prev = filler->he.left_top;
			filler->he.rb_prev = filler->he.right_bottom;
			ft_bzero(&filler->he.right_bottom, sizeof(t_point));
			ft_bzero(&filler->he.left_top, sizeof(t_point));
		}
		else
		{
			if (ft_memcmp(&filler->he.left_top, &filler->he.lt_prev,\
			sizeof(t_point)))
				filler->he.priority = filler->he.left_top;
			else
				filler->he.priority = filler->he.right_bottom;
		}
	}
}

int			solution(t_filler *filler)
{
	if (filler->map.map && filler->piece.piece)
	{
		heatmap(filler);
		cut_figure(filler);
		enemy_position(filler);
		set_priority(filler, 0);
		find_place(filler);
		normalize_place(filler);
		clean_two_dim((void ***)&filler->piece.piece);
		ft_putnbr(filler->piece.place.y);
		ft_putchar(32);
		ft_putnbr(filler->piece.place.x);
		ft_putchar('\n');
		ft_bzero(&filler->piece, sizeof(t_piece));
		set_priority(filler, 1);
	}
	return (1);
}
