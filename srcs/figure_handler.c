/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			set_top_f(t_filler *filler)
{
	int		h;

	h = 0;
	while (h < filler->piece.h)
	{
		if (ft_strchr(filler->piece.piece[h], '*'))
		{
			filler->piece.top = h;
			return ;
		}
		h++;
	}
}

static void			set_left_f(t_filler *filler)
{
	int		h;
	int		w;
	int		left;

	h = 0;
	left = filler->piece.w - 1;
	while (h < filler->piece.h)
	{
		w = 0;
		while (w < filler->piece.w)
		{
			if (filler->piece.piece[h][w] == '*' && w < left)
			{
				left = w;
				break ;
			}
			w++;
		}
		h++;
	}
	filler->piece.left = left;
}

static void			set_right_f(t_filler *filler)
{
	int		h;
	int		w;
	int		right;

	h = 0;
	right = 0;
	while (h < filler->piece.h)
	{
		w = filler->piece.w - 1;
		while (w >= 0)
		{
			if (filler->piece.piece[h][w] == '*' && w > right)
			{
				right = w;
				break ;
			}
			w--;
		}
		h++;
	}
	filler->piece.right = right;
}

static void			set_bottom_f(t_filler *filler)
{
	int		h;

	h = filler->piece.h - 1;
	while (h >= 0)
	{
		if (ft_strchr(filler->piece.piece[h], '*'))
		{
			filler->piece.bottom = h;
			return ;
		}
		h--;
	}
}

void				cut_figure(t_filler *filler)
{
	set_top_f(filler);
	set_left_f(filler);
	set_right_f(filler);
	set_bottom_f(filler);
	filler->piece.real_h = filler->piece.bottom - filler->piece.top + 1;
}
