/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:45:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/01/05 16:57:23 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		ft_isdirection(char *dir)
{
	if ((ft_strcmp(dir, "NO")) == 0)
		return (1);
	if ((ft_strcmp(dir, "SO")) == 0)
		return (1);
	if ((ft_strcmp(dir, "WE")) == 0)
		return (1);
	if ((ft_strcmp(dir, "EA")) == 0)
		return (1);
	return (0);
}
