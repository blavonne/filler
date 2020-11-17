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
