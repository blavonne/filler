/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	set_delay(t_filler *filler, int key)
{
	if (key == NUM_MINUS)
	{
		if (filler->delay - 100000 >= 0)
			filler->delay -= 100000;
		else
			filler->delay = 0;
	}
	else if (key == NUM_PLUS)
	{
		if (filler->delay + 100000 <= 1000000)
			filler->delay += 100000;
		else
			filler->delay = 1000000;
	}
}

int			deal_key(int key, t_filler *filler)
{
	if (key == ESC)
		clean_exit(filler);
	else if (key == NUM_PLUS || key == NUM_MINUS)
		set_delay(filler, key);
	return (0);
}
