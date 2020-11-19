/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:29:17 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:29:26 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_base.h"

t_complex	complex_init(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_point		point_init(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_complex	not_random(void)
{
	t_complex	c;

	c.re = (double)rand() / (double)RAND_MAX * 4 - 2;
	c.im = (double)rand() / (double)RAND_MAX * 4 - 2;
	return (c);
}

t_point		complex_to_screen(t_complex complex, t_complex size, t_complex min,\
		t_point start)
{
	t_point		point;

	point.x = (int)round(start.x + ((WIDTH - 1) / size.re * (complex.re -\
	min.re)));
	point.y = ((int)round(start.y - HEIGHT + HEIGHT / size.im * (complex.im -\
	min.im)));
	return (point);
}

t_complex	screen_to_complex(t_point point, t_complex size, t_point min,\
		t_complex start)
{
	t_complex	complex;

	complex.re = start.re + size.re / WIDTH * (point.x - min.x);
	complex.im = -(start.im + size.im / HEIGHT * (point.y - min.y));
	return (complex);
}
