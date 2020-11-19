/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		set_player_sign(char position, t_filler *filler)
{
	if (position == '1' || position == '2')
	{
		if (position == '1')
		{
			filler->me.sign = 'O';
			filler->he.sign = 'X';
		}
		else
		{
			filler->me.sign = 'X';
			filler->he.sign = 'O';
		}
		return (1);
	}
	return (0);
}

int				parse_player(t_filler *filler)
{
	char	*line;

	if (get_next_line(0, &line) > 0)
	{
		if (line && ft_strlen(line) > 10 && !ft_strncmp(line, "$$$ exec p", 9))
		{
			if (set_player_sign(line[10], filler))
			{
				free(line);
				return (1);
			}
		}
	}
	free(line);
	return (0);
}
