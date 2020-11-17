#include "filler.h"

int			find_place(t_filler *filler)
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
			sum = find_min(filler, w, h, &res);
			if (sum && sum < min_sum)
			{
				min_sum = sum;
				filler->piece.place = res;
			}
			w++;
		}
		h++;
	}
	if (sum)
		return (1);
	else
		return (0);
}

void		normalize_place(t_filler *filler)
{
	filler->piece.place.x -= filler->piece.left.x;
	filler->piece.place.y -= filler->piece.top.y;
}

int			solution(t_filler *filler)
{
	int		fd;

	if (filler->map.map && filler->piece.piece)
	{
		fd = open("/home/blavonne/CLionProjects/filler/test.txt", O_RDWR|O_APPEND\
	|O_CREAT);
		to_file(filler);
		heatmap(filler);
		heat_to_file(filler);
		cut_figure(filler);
		find_place(filler);
		normalize_place(filler);
		clean_two_dim((void ***)&filler->piece.piece);
		ft_putstr_fd("My coords: ", fd);
		ft_putstr_fd(ft_itoa(filler->piece.place.x), fd);
		ft_putstr_fd(" ", fd);
		ft_putstr_fd(ft_itoa(filler->piece.place.y), fd);
		ft_putstr_fd("\n", fd);
		ft_putnbr(filler->piece.place.x);
		ft_putchar(32);
		ft_putnbr(filler->piece.place.y);
		ft_putchar('\n');
		ft_bzero(&filler->piece, sizeof(t_piece));
		close(fd);
	}
	return (1);
}
