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
			if (filler->me.sign == 'O')
			{
				if (sum && sum <= min_sum)
				{
					min_sum = sum;
					filler->piece.place = res;
				}
			}
			else if (filler->me.sign == 'X')
			{
				if (sum && sum < min_sum)
				{
					min_sum = sum;
					filler->piece.place = res;
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

int			solution(t_filler *filler)
{
	if (filler->map.map && filler->piece.piece)
	{
		to_file(filler);
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
	}
	return (1);
}
