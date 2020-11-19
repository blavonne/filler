/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:28:16 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:28:17 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_base.h"

t_argb			int_to_argb(unsigned int value)
{
	t_argb	color;

	color.channel[0] = value >> 24u;
	color.channel[1] = value >> 16u;
	color.channel[2] = value >> 8u;
	color.channel[3] = value;
	return (color);
}

void			colorize(unsigned char *img, int width, int heigh,\
		unsigned int color)
{
	t_argb	argb;
	int		i;

	i = 0;
	argb = int_to_argb(color);
	while (i < width * heigh * (int)sizeof(int))
	{
		img[i++] = argb.channel[3];
		img[i++] = argb.channel[2];
		img[i++] = argb.channel[1];
		img[i++] = argb.channel[0];
	}
}
