/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maprange_clamped.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:19:17 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 15:56:26 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
** set a range value to another range value
*/

float		ft_map_range_clamped(float value, t_vector inrange,
	t_vector outrange)
{
	float		newvalue;

	newvalue = (((value - inrange.x) * (outrange.y - outrange.x)) /
	(inrange.y - inrange.x)) + outrange.x;
	return (newvalue);
}
