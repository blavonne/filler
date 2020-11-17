#include "filler.h"





int			put_figure(t_filler *filler)
{
	int		h;
	int		w;
	int		sum;
	int		min_sum;
	t_point	res;

	h = 0;
	min_sum = filler->map.h * filler->map.w;
	while (h < filler->map.h)
	{
		w = 0;
		while (w < filler->map.w)
		{
			if (filler->map.map[h][w] == filler->me.sign)
			{
				sum = try_to(filler);
			}
		}
	}
}



int			solution(t_filler *filler)
{
	if (filler->map.map && filler->piece.piece)
	{
		to_file(filler);
		heatmap(filler);
		cut_figure(filler);
		put_figure(filler);
		clean_split(&filler->piece.piece);
	}
	return (1);
}
