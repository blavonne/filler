/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

/*
** use only for debug!!! functions open|close are forbidden!!!
** O_RDWR | O_APPEND | O_CREAT
** rdwr - read and write, append - add in end, creat - if does not exist
*/

int			str_to_file(char *path, int flag, char *str)
{
	int		fd;

	if ((fd = open(path, flag) >= 0))
		ft_putendl_fd(str, fd);
	close(fd);
	return (fd);
}
