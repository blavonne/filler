/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	start_from(int *y, t_filler *filler)
{
	int		h;

	h = 0;
	while (h < filler->map.h)
	{
		if (ft_strchr(filler->map.map[h], filler->me.sign))
		{
			*y = h - filler->piece.real_h;
			if (*y < 0)
				*y = filler->piece.real_h - 1;
			return ;
		}
		h++;
	}
}

static void	find_place(t_filler *filler)
{
	int		h;
	int		w;
	int		sum;
	int		min_sum;

	min_sum = INT_MAX;
	start_from(&h, filler);
	while (h < filler->map.h)
	{
		w = 0;
		while (w < filler->map.w)
		{
			sum = find_min(filler, w, h);
			if (sum && sum < min_sum)
			{
				min_sum = sum;
				filler->piece.place = point_init(w, h);
			}
			w++;
		}
		h++;
	}
}

void		normalize_place(t_filler *filler)
{
	filler->piece.place.x -= filler->piece.left;
	filler->piece.place.y -= filler->piece.top;
}

void		find_enemy(char **heat, char **map, char sign)
{
	int		h;
	int		w;

	h = 0;
	while (map[h])
	{
		w = 0;
		while (map[h][w])
		{
			if (map[h][w] == sign)
				heat[h][w] = sign;
			w++;
		}
		h++;
	}
}

int			solution(t_filler *filler)
{
	if (filler->map.map && filler->piece.piece && filler->map.heat)
	{
		find_enemy(filler->map.heat, filler->map.map, filler->he.sign);
		heatmap(filler, filler->he.sign, 2);
		cut_figure(filler);
		find_place(filler);
		normalize_place(filler);
		clear_heatmap(filler);
		ft_putnbr(filler->piece.place.y);
		ft_putchar(32);
		ft_putnbr(filler->piece.place.x);
		ft_putchar('\n');
		clean_two_dim((void ***)&filler->piece.piece);
		ft_bzero(&filler->piece, sizeof(t_piece));
	}
	return (1);
}
