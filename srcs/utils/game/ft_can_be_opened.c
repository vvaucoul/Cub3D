/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_be_opened.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:00:46 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/21 17:06:58 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_bool		ft_can_be_opened(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	close(fd);
	if (fd < 0)
		return (FALSE);
	return (TRUE);
}
