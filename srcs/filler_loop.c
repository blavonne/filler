/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	line = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (!parse_w_h(filler, line))
			break ;
		if (!map_init(filler))
			break ;
		if (!parse_map(filler, line))
			break ;
		if (!piece_init(filler))
			break ;
		if (!parse_piece(filler, line))
			break ;
		solution(filler);
		free(line);
	}
	mlx_key_hook(filler->mlx.win, clean_exit, filler);
	mlx_hook(filler->mlx.win, 17, 1L << 17, clean_exit2, filler);
	mlx_loop(filler->mlx.mlx);
	free(line);
	if (filler->map.map)
		clean_two_dim((void ***)&filler->map.map);
	if (filler->piece.piece)
		clean_two_dim((void ***)&filler->piece.piece);
	clean_mlx(&filler->mlx);
	return (1);
}
