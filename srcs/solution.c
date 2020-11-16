#include "filler.h"


char		calc_distance(t_filler *filler, int x, int y)
{
	int		h;
	int		w;
	int		dist;
	int		min_dist;

	h = 0;
	min_dist = filler->map.h * filler->map.w;
	while (h < filler->map.h)
	{
		w = 0;
		while (w < filler->map.w)
		{
			if (filler->map.map[h][w] == filler->he.sign)
			{
				dist = ft_abs(w - x) + ft_abs(h - y);
				if (dist < min_dist)
					min_dist = dist;
			}
			w++;
		}
		h++;
	}
	return ((char)dist);
}

int			heatmap(t_filler *filler)
{
	int		h;
	int		w;

	h = 0;
	while (h < filler->map.h)
	{
		w = 0;
		while (w < filler->map.w)
		{
			if (filler->map.map[h][w] == '.')
				filler->map.map[h][w] = calc_distance(filler, w, h);
			w++;
		}
		h++;
	}
	return (0);
}

int			solution(t_filler *filler)
{
	if (filler->map.map && filler->piece.piece)
	{
		to_file(filler);
		heatmap(filler);
		clean_split(&filler->piece.piece);
	}
	return (1);
}
