/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:48:53 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 15:48:55 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_base.h"

static void		prepare_coords(t_point *start, t_point *end, int *steep)
{
	end->y = -end->y;
	start->y = -start->y;
	*steep = (abs(end->y - start->y) > abs(end->x - start->x)) ? 1 : 0;
	if (*steep)
	{
		ft_swap(&start->x, &start->y);
		ft_swap(&end->x, &end->y);
	}
	if (start->x > end->x)
	{
		ft_swap(&start->x, &end->x);
		ft_swap(&start->y, &end->y);
	}
}

static void		sketch(t_mlx *mlx, t_point cur, int steep)
{
	int		i;

	if (steep)
		ft_swap(&cur.x, &cur.y);
	i = (cur.x * mlx->image.bps / 8) + (cur.y *\
	mlx->image.size_line);
	if (i >= 0 && i < WIDTH * HEIGHT * (int)sizeof(int))
	{
		mlx->image.img[i++] = mlx->argb.channel[3];
		mlx->image.img[i++] = mlx->argb.channel[2];
		mlx->image.img[i++] = mlx->argb.channel[1];
		mlx->image.img[i] = mlx->argb.channel[0];
	}
}

void			draw_line(t_point start, t_point end, t_mlx *mlx)
{
	int		steep;
	t_point	delta;
	int		error;
	int		offset_y;
	t_point	cur;

	prepare_coords(&start, &end, &steep);
	delta.x = end.x - start.x;
	delta.y = abs(end.y - start.y);
	error = delta.x / 2;
	offset_y = start.y < end.y ? 1 : -1;
	cur = start;
	if (!mlx->image.ptr)
		mlx->image = create_img(mlx, WIDTH, HEIGHT);
	while (cur.x <= end.x)
	{
		sketch(mlx, cur, steep);
		error -= delta.y;
		if (error < 0)
		{
			cur.y += offset_y;
			error += delta.x;
		}
		cur.x++;
	}
}
