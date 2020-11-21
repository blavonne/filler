/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			clear_heatmap(t_filler *filler)
{
	int		h;

	h = 0;
	while (h < filler->map.h)
	{
		ft_memset(filler->map.heat[h], 1, filler->map.w);
		h++;
	}
}

static int		check_round(t_filler *filler, int w, int h, char find)
{
	if ((w - 1 >= 0 && filler->map.heat[h][w - 1] == find) || \
	(w + 1 < filler->map.w && filler->map.heat[h][w + 1] == find) || \
	(h - 1 >= 0 && filler->map.heat[h - 1][w] == find) || \
	(h + 1 < filler->map.h && filler->map.heat[h + 1][w] == find) || \
	(w - 1 >= 0 && h - 1 >= 0 && filler->map.heat[h - 1][w - 1] == find) ||\
	(w - 1 >= 0 && h + 1 < filler->map.h && \
	filler->map.heat[h + 1][w - 1] == find) ||\
	(w + 1 < filler->map.w && h - 1 >= 0 && filler->map.heat[h - 1][w + 1] ==\
	find) ||\
	(w + 1 < filler->map.w && h + 1 < filler->map.h &&\
	filler->map.heat[h + 1][w + 1] == find))
		return (1);
	return (0);
}

static int		is_empty(char **map, int h)
{
	int		i;

	i = 0;
	while (i < h)
	{
		if (ft_strchr(map[i], 1))
			return (0);
		i++;
	}
	return (1);
}

int				heatmap(t_filler *filler, char find, char replace)
{
	int		h;
	int		w;

	h = 0;
	while (h < filler->map.h)
	{
		w = 0;
		while (w < filler->map.w)
		{
			if (filler->map.heat[h][w] == 1)
			{
				if (check_round(filler, w, h, find))
					filler->map.heat[h][w] = replace;
			}
			w++;
		}
		h++;
	}
	if (!is_empty(filler->map.heat, filler->map.h))
		heatmap(filler, replace, (char)(replace + 1));
	return (1);
}
