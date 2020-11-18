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

void		set_enemy_top(t_filler *filler)
{
	int		h;
	int		w;

	h = 0;
	while (h < filler->map.h)
	{
		w = 0;
		while (w < filler->map.w)
		{
			if (filler->map.map[h][w] == filler->he.sign)
			{
				filler->he.top = h;
				return ;
			}
			w++;
		}
		h++;
	}
}

int			set_bottom(t_filler *filler, char sign)
{
	int		h;
	int		w;

	h = filler->map.h - 1;
	while (h >= 0)
	{
		w = filler->map.w - 1;
		while (w >= 0)
		{
			if (filler->map.map[h][w] == sign)
				return (h);
			w--;
		}
		h--;
	}
	return (0);
}

int			set_top(t_filler *filler, char sign)
{
	int		h;
	int		w;

	h = 0;
	while (h < filler->map.h)
	{
		w = 0;
		while (w < filler->map.w)
		{
			if (filler->map.map[h][w] == sign)
				return (h);
			w++;
		}
		h++;
	}
	return (0);
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
	min_sum = INT_MAX;
	res = point_init(0, 0);
	filler->piece.place = res;
	start_from(&h, filler);
	filler->me.top = set_top(filler, filler->me.sign);
	filler->me.bottom = set_bottom(filler, filler->me.sign);
	filler->he.top = set_top(filler, filler->he.sign);
	filler->he.bottom = set_bottom(filler, filler->he.sign);
	while (h < filler->map.h)
	{
		w = 0;
		while (w < filler->map.w)
		{
			sum = find_min(filler, w, h, &res);
//			if (sum && sum < min_sum)
//			{
//				min_sum = sum;
//				filler->piece.place = res;
//			}
			if (filler->position == 't')
			{
				if (filler->me.bottom < filler->he.top)
				{
					if (sum && sum <= min_sum)
					{
						min_sum = sum;
						filler->piece.place = res;
					}
				}
				else
				{
					if (sum && sum < min_sum)
					{
						min_sum = sum;
						filler->piece.place = res;
					}
				}
			}
			else if (filler->position == 'b')
			{
				if (filler->me.top < filler->he.top)
				{
					if (sum && sum <= min_sum)
					{
						min_sum = sum;
						filler->piece.place = res;
					}
				}
				else
				{
					if (sum && sum < min_sum)
					{
						min_sum = sum;
						filler->piece.place = res;
					}
				}
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

void		set_position(t_filler *filler)
{
	int		me;
	int		he;

	me = set_top(filler, filler->me.sign);
	he = set_top(filler, filler->he.sign);
	if (!filler->position)
	{
		if (me && he && me < he)
			filler->position = 't';
		else if (me && he)
			filler->position = 'b';
	}
}

int			solution(t_filler *filler)
{
	if (filler->map.map && filler->piece.piece)
	{
		set_position(filler);
//		to_file(filler);
		heatmap(filler);
//		heat_to_file(filler);
		cut_figure(filler);
		find_place(filler);
		normalize_place(filler);
		clean_two_dim((void ***)&filler->piece.piece);
		ft_putnbr(filler->piece.place.y);
		ft_putchar(32);
		ft_putnbr(filler->piece.place.x);
		ft_putchar('\n');
		ft_bzero(&filler->piece, sizeof(t_piece));
		filler->iter++;
	}
	return (1);
}
