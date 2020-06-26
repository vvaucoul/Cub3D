/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdirection_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:45:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 15:49:19 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		ft_isdirection_map(char dir)
{
	if (dir == 'N')
		return (1);
	if (dir == 'S')
		return (2);
	if (dir == 'W')
		return (3);
	if (dir == 'E')
		return (4);
	return (0);
}
