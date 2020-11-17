#include "filler.h"

int			find_min(t_filler *filler, int w, int h, t_point *res)
{
	int		i;
	int		j;
	int		cross;
	int		sum;
	int		fd;

	fd = open("/home/blavonne/CLionProjects/filler/test.txt", O_RDWR|O_APPEND\
	|O_CREAT);
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
				ft_putstr_fd("Piece is *\n", fd);
				if (filler->map.map[h][w] == filler->he.sign)
				{
					ft_putstr_fd("Piece is enemy! Coords: ", fd);
					ft_putstr_fd(ft_itoa(h), fd);
					ft_putstr_fd(" ", fd);
					ft_putstr_fd(ft_itoa(w), fd);
					ft_putstr_fd("\n", fd);
					close(fd);
					return (0);
				}
				else if (filler->map.map[h][w] == filler->me.sign)
				{
					ft_putstr_fd("Piece crosses map! Coords: ", fd);
					ft_putstr_fd(ft_itoa(h), fd);
					ft_putstr_fd(" ", fd);
					ft_putstr_fd(ft_itoa(w), fd);
					ft_putstr_fd("\n", fd);
					cross++;
				}
				else
				{
					ft_putstr_fd("Piece passed! Coords: ", fd);
					ft_putstr_fd(ft_itoa(h), fd);
					ft_putstr_fd(" ", fd);
					ft_putstr_fd(ft_itoa(w), fd);
					ft_putstr_fd("\n", fd);
					sum += filler->map.map[h][w];
				}
				if (cross > 1)
				{
					ft_putstr_fd("Too much crosses!\n", fd);
					close(fd);
					return (0);
				}
			}
			i++;
			w++;
		}
		j++;
		h++;
	}
	ft_putstr_fd("Put finished.\nj is ", fd);
	ft_putstr_fd(ft_itoa(j), fd);
	ft_putstr_fd(", i is ", fd);
	ft_putstr_fd(ft_itoa(i), fd);
	ft_putstr_fd("\n", fd);
	ft_putstr_fd("Sum is ", fd);
	ft_putstr_fd(ft_itoa(sum), fd);
	ft_putstr_fd("\n", fd);
	close(fd);
	if (j == filler->piece.bottom.y + 1 && i == filler->piece.right.x + 1 &&\
	cross)
		return (sum);
	return (0);
}
