/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler filler;
	char	*line;

	ft_bzero(&filler, sizeof(filler));
	if (!parse_player(&filler))
		return (0);
	if (get_next_line(0, &line) > 0)
	{
		parse_w_h(&filler, line);
		ft_strdel(&line);
	}
	if (!(mlx_filler_loop(&filler)))
	{
		clean(&filler);
		return (0);
	}
	return (0);
}
