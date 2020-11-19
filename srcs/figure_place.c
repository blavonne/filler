#include "filler.h"

int			check_str(t_filler *filler, int w, int h, int j)
{
	int		i;
	int		sum;

	sum = 0;
	i = filler->piece.left;
	while (i <= filler->piece.right && w < filler->map.w)
	{
		if (filler->piece.piece[j][i] == '*')
		{
			if (filler->map.map[h][w] == filler->he.sign)
				return (-1);
			else if (filler->map.map[h][w] == filler->me.sign)
				filler->piece.cross++;
			else
				sum += filler->map.map[h][w];
			if (filler->piece.cross > 1)
				return (-1);
		}
		i++;
		w++;
	}
	if (i == filler->piece.right + 1)
		return (sum);
	else
		return (-1);
}

int			find_min(t_filler *filler, int w, int h)
{
	int		j;
	int		sum;
	int		res;

	j = filler->piece.top;
	filler->piece.cross = 0;
	sum = 0;
	while (j <= filler->piece.bottom && h < filler->map.h)
	{
		res = check_str(filler, w, h, j);
		if (res > -1)
			sum += res;
		else
			return (0);
		j++;
		h++;
	}
	if (j == filler->piece.bottom + 1 && filler->piece.cross == 1)
		return (sum);
	return (0);
}
