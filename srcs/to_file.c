#include "filler.h"

int			to_file(t_filler *filler)
{
	int		fd;
	int		i;

	i = 0;
	fd = open("/home/blavonne/CLionProjects/filler/test.txt", O_RDWR|O_APPEND\
	|O_CREAT);
	write(fd, "\nMy sign is: ", 13);
	write(fd, &filler->me.sign, 1);
	write(fd, "\nPiece:\n", 8);
	while (i < filler->piece.h)
	{
		write(fd, filler->piece.piece[i], ft_strlen(filler->piece.piece[i]));
		write(fd, "\n", 1);
		i++;
	}
	i = 0;
	write(fd, "\nMap is:\n", 9);
	while (i < filler->map.h)
	{
		write(fd, filler->map.map[i], ft_strlen((char *)filler->map.map[i]));
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
	return (0);
}

void	heat_to_file(t_filler *filler)
{
	int		fd;
	int		i;
	int		j;

	i = 0;
	fd = open("/home/blavonne/CLionProjects/filler/test.txt", O_RDWR|O_APPEND\
	|O_CREAT);
	ft_putstr_fd("Heatmap is: \n", fd);
	while (i < filler->map.h)
	{
		j = 0;
		while (j < filler->map.w)
		{
			if (filler->map.map[i][j] == filler->me.sign)
				ft_putstr_fd("O", fd);
			else if (filler->map.map[i][j] == filler->he.sign)
				ft_putstr_fd("X", fd);
			else
				ft_putstr_fd(ft_itoa(filler->map.map[i][j]), fd);
			ft_putstr_fd(" ", fd);
			j++;
		}
		ft_putstr_fd("\n", fd);
		i++;
	}
	close(fd);
}

void		figure_to_file(t_filler *filler)
{
	int		fd;

	fd = open("/home/blavonne/CLionProjects/filler/test.txt", O_RDWR|O_APPEND\
	|O_CREAT);
	ft_putstr_fd("Coords of figure are:\n(left, top)(", fd);
	ft_putstr_fd(ft_itoa(filler->piece.left_top.x), fd);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(ft_itoa(filler->piece.left_top.y), fd);
	ft_putstr_fd(")\n", fd);
	ft_putstr_fd("(bottom, right)(", fd);
	ft_putstr_fd(ft_itoa(filler->piece.right_bottom.x), fd);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(ft_itoa(filler->piece.right_bottom.y), fd);
	ft_putstr_fd(")\n", fd);
	close(fd);
}