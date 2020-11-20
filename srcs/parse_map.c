/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				heatmap_init(t_filler *filler)
{
	int		i;

	i = 0;
	if (!filler->map.heat)
	{
		if (filler->map.w && filler->map.h)
		{
			if (!(filler->map.heat = (char **)malloc(sizeof(char *) * \
		(filler->map.h + 1))))
				return (0);
			filler->map.heat[filler->map.h] = NULL;
			while (i < filler->map.h)
			{
				if (!(filler->map.heat[i] = ft_strnew(filler->map.w)))
					return (emergency_clean(i, &filler->map.heat));
				ft_memset(filler->map.heat[i], 1, filler->map.w);
				i++;
			}
		}
	}
	return (1);
}

int				map_init(t_filler *filler)
{
	int		i;

	i = 0;
	if (!filler->map.map)
	{
		if (filler->map.w && filler->map.h)
		{
			if (!(filler->map.map = (char **)malloc(sizeof(char *) *\
		(filler->map.h + 1))))
				return (0);
			filler->map.map[filler->map.h] = NULL;
			while (i < filler->map.h)
			{
				if (!(filler->map.map[i] = ft_strnew(filler->map.w)))
					return (emergency_clean(i, &filler->map.map));
				i++;
			}
		}
	}
	return (heatmap_init(filler));
}

int				parse_map(t_filler *filler, char *line)
{
	char	*tmp;
	int		i;

	tmp = 0;
	i = 0;
	if (line && !ft_strncmp(line, "    0123", 8))
	{
		while (i >= 0 && i < filler->map.h)
		{
			if (get_next_line(0, &tmp) > 0 && (int)ft_strlen(tmp) ==\
			filler->map.w + 4)
				filler->map.map[i] = ft_strcpy(filler->map.map[i], tmp + 4);
			else
				i = -21;
			ft_strdel(&tmp);
			i++;
		}
		if (i < 0)
			return (0);
		usleep(filler->delay);
		filler_draw(filler);
	}
	return (1);
}
