#include "filler.h"

int			find_min(t_filler *filler, int w, int h)
{
	int		i;
	int		j;
	int		cross;
	int		sum;
	int		w_default;

	j = filler->piece.top;
	cross = 0;
	w_default = w;
	sum = 0;
	while (j <= filler->piece.bottom && h < filler->map.h)
	{
		i = filler->piece.left;
		w = w_default;
		while (i <= filler->piece.right && w < filler->map.w)
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
	if (j == filler->piece.bottom + 1 && i == filler->piece.right + 1 &&\
	cross)
		return (sum);
	return (0);
}
