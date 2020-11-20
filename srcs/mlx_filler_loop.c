/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_filler_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		prepare_to_draw(t_filler *filler)
{
	if (!filler->win_h)
	{
		filler->margin = 2;
		filler->square_len = (filler->map.h > 50 ? 5 : 15);
		filler->delay = (filler->map.h > 50 ? 0 : 15000);
		filler->win_w = filler->map.w * filler->square_len + (filler->map.w)\
		* filler->margin;
		filler->win_h = filler->map.h * filler->square_len + (filler->map.h)\
		* filler->margin;
	}
}

static int		safe_mlx_create(t_mlx *mlx, int w, int h, char sign)
{
	char		*name;

	if (!mlx->mlx)
	{
		if (!(name = ft_strjoin("Filler by blavonne as ", (sign == 'O') ?\
		"light" : "dark")))
			return (0);
		if (!(mlx->mlx = create_mlx()))
		{
			ft_strdel(&name);
			return (0);
		}
		if (!(mlx->win = create_win(mlx, w, h, name)))
		{
			ft_strdel(&name);
			free(mlx->mlx);
			return (0);
		}
		ft_strdel(&name);
		create_background(mlx, w, h, 0xffffff);
		mlx->image = create_img(mlx, w, h);
		colorize(mlx->image.img, w, h, 0x969F34);
	}
	return (1);
}

int				mlx_filler_loop(t_filler *filler)
{
	if (filler->map.w && filler->map.h)
	{
		prepare_to_draw(filler);
		if (!(safe_mlx_create(&filler->mlx, filler->win_w, filler->win_h,\
		filler->me.sign)))
			return (0);
		mlx_loop_hook(filler->mlx.mlx, filler_loop, filler);
		mlx_key_hook(filler->mlx.win, deal_key, filler);
		mlx_hook(filler->mlx.win, 17, 1L << 17, clean_exit, filler);
		mlx_loop(filler->mlx.mlx);
	}
	return (1);
}
