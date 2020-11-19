/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_trig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:48:47 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 15:48:49 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_base.h"

t_complex	complex_sin(t_complex z)
{
	t_complex	res;

	res.re = sin(z.re) * cosh(z.im);
	res.im = -cos(z.re) * sinh(z.im);
	return (res);
}

t_complex	complex_cos(t_complex z)
{
	t_complex	res;

	res.re = cos(z.re) * cosh(z.im);
	res.im = -sin(z.re) * sinh(z.im);
	return (res);
}

t_complex	complex_tg(t_complex z)
{
	t_complex	res;

	res = complex_div(complex_sin(z), complex_cos(z));
	return (res);
}

t_complex	complex_derivative(t_complex z, int k)
{
	int		power;

	power = k - 1;
	z = complex_power(z, power);
	z.re = k * (z.re);
	z.im = k * (z.im);
	return (z);
}

t_complex	complex_ln(t_complex z)
{
	z.re = 0.5 * log(pow(z.re, 2) + pow(z.im, 2));
	z.im = atan(z.im / z.re) + M_PI;
	return (z);
}
