/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 03:40:28 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 15:50:41 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
** Square function
** And calculate a distance with pos1 and pos2
*/

float	sqr(float a)
{
	return (a * a);
}

float	ft_distance(t_vector pos1, t_vector pos2)
{
	return (sqrtf(sqr(pos2.y - pos1.y) + sqr(pos2.x - pos1.x)));
}
