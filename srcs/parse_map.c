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

int				emergency_clean(int last, unsigned char ***arr)
{
	unsigned char	**tmp;

	tmp = *arr;
	while (--last >= 0)
		free(tmp[last]);
	free(tmp);
	*arr = NULL;
	return (0);
}

int				map_init(t_filler *filler)
{
	int		i;

	i = 0;
	if (filler->map.w && filler->map.h && !filler->map.map)
	{
		if (!(filler->map.map = (unsigned char **)malloc(sizeof(char *) *\
		(filler->map.h + 1))))
			return (0);
		filler->map.map[filler->map.h] = NULL;
		while (i < filler->map.h)
		{
			if (!(filler->map.map[i] = (unsigned char *)malloc(sizeof(char) *\
			(filler->map.w + 1))))
				return (emergency_clean(i, &filler->map.map));
			i++;
		}
	}
	return (1);
}

int				parse_map(t_filler *filler, char *line)
{
	char	*tmp;
	int		i;

	tmp = 0;
	i = 0;
	if (line && !ft_strncmp(line, "    0123", 8))
	{
		while (i < filler->map.h)
		{
			if (get_next_line(0, &tmp) > 0)
			{
				filler->map.map[i] = (unsigned char *)ft_strcpy(\
				(char *)filler->map.map[i], tmp + 4);
				ft_strdel(&tmp);
				i++;
			}
			else
			{
				ft_strdel(&tmp);
				return (0);
			}
		}
	}
	return (1);
}
