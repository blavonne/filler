#include "filler.h"

int			find_min(t_filler *filler, int w, int h, t_point *res)
{
	int		i;
	int		j;
	int		cross;
	int		sum;

	j = filler->piece.top.y;
	cross = 0;
	(*res) = point_init(w, h);
	sum = 0;
	while (j <= filler->piece.bottom.y && h < filler->map.h)
	{
		i = filler->piece.left.x;
		w = (*res).x;
		while (i <= filler->piece.right.x && w < filler->map.w)
		{
			if (filler->piece.piece[j][i] == '*')
			{
				if (filler->map.map[h][w] == filler->he.sign)
					return (0);
				else if (filler->map.map[h][w] == filler->me.sign)
					cross++;
				else
					sum += filler->map.map[h][w];
				if (cross > 1)
					return (0);
			}
			i++;
			w++;
		}
		j++;
		h++;
	}
	if (j == filler->piece.bottom.y + 1 && i == filler->piece.right.x + 1 &&\
	cross)
		return (sum);
	return (0);
}
