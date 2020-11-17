#include "filler.h"

int				set_exception(int dist)
{
	dist += 32;
	if (dist >= 46)
		dist++;
	if (dist >= 79)
		dist++;
	if (dist >= 88)
		dist++;
	return (dist);
}

/*
* 46 is dot .
* 79 is 'O'
* 88 is 'X'
*/

unsigned char	calc_distance(t_filler *filler, int x, int y)
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
	dist = set_exception(dist);
	return (dist);
}

int				heatmap(t_filler *filler)
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
