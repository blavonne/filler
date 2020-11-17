#include "filler.h"

/*
* 45 is dot .
* 79 is 'O'
*/

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
	if ((dist > 45 && dist < 79) || dist > 79)
		dist++;
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
