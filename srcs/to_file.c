/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

int			to_file(t_filler *filler)
{
	int		fd;
	int		i;

	i = 0;
	fd = open("/home/blavonne/CLionProjects/filler/test.txt", O_RDWR | O_APPEND\
	| O_CREAT);
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

void		heat_to_file(t_filler *filler)
{
	int		fd;
	int		i;
	int		j;

	i = 0;
	fd = open("/home/blavonne/CLionProjects/filler/test.txt", O_RDWR | O_APPEND\
	| O_CREAT);
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
