#include "filler.h"

int			parse_w_h(t_filler *filler, char *line)
{
	char		**split;
	char		type;

	if (ft_strstr(line, "Plateau"))
		type = 'P';
	else if (ft_strstr(line, "Piece"))
		type = 'p';
	else
		return (1);
	split = 0;
	if (!(split = ft_strsplit(line, 32)))
		return (0);
	if (type == 'P')
	{
		filler->map.h = ft_atoi(split[1]);
		filler->map.w = ft_atoi(split[2]);
	}
	else
	{
		filler->piece.h = ft_atoi(split[1]);
		filler->piece.w = ft_atoi(split[2]);
	}
	clean_two_dim((void ***)&split);
	return (1);
}

int			filler_loop(t_filler *filler)
{
	char	*line;
	int		fd;

	line = 0;
	fd = open("/home/blavonne/CLionProjects/filler/test.txt", O_RDWR|O_APPEND\
	|O_CREAT);
	while (get_next_line(0, &line) > 0)
	{
		write(fd, "Filler loop: ", 13);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		if (!parse_w_h(filler, line))
			return (0);
		if (!map_init(filler))
			return (0);
		if (!parse_map(filler, line))
			return (0);
		if (!piece_init(filler))
			return (0);
		if (!parse_piece(filler, line))
			return (0);
		if (!solution(filler))
			return (0);
		free(line);
	}
	write(fd, "Finish\n", 7);
	free(line);
	clean_two_dim((void ***)&filler->map.map);
	close(fd);
	return (1);
}