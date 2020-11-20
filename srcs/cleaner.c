/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		clean_two_dim(void ***arr)
{
	unsigned char	**ptr;
	int				i;

	i = 0;
	ptr = (unsigned char **)*arr;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	*arr = NULL;
}

int			clean_exit(t_filler *filler)
{
	clean_mlx(&filler->mlx);
	if (filler->map.map)
		clean_two_dim((void ***)&filler->map.map);
	if (filler->piece.piece)
		clean_two_dim((void ***)&filler->piece.piece);
	exit(1);
}

void		clean_mlx(t_mlx *mlx)
{
	if (mlx->image.ptr)
		mlx_destroy_image(mlx->mlx, mlx->image.ptr);
	if (mlx->background.ptr)
		mlx_destroy_image(mlx->mlx, mlx->background.ptr);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		free(mlx->mlx);
}
