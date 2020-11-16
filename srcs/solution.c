#include "filler.h"

//int			heatmap(t_filler *filler)
//{
//	int		h;
//	int		w;
//
//	h = 0;
//	while (h < filler->map.h)
//	{
//		w = 0;
//		while (w < filler->map.w)
//		{
//
//		}
//	}
//}

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
		write(fd, filler->map.map[i], ft_strlen(filler->map.map[i]));
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
	return (0);
}

int			solution(t_filler *filler)
{
	if (filler->map.map && filler->piece.piece)
	{
		to_file(filler);
		clean_split(&filler->piece.piece);
	}
	return (1);
}
