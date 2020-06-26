/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_clamp_vector_to_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:52:44 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 16:05:44 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
** Clamp coord into another coords
*/

t_vector	v_clamp_vector_to_size(t_vector coord, t_vector bloc_coord,
	float bloc_size)
{
	t_vector	newcoord;
	float		med_x;
	float		med_y;

	newcoord = v_init_vector(0, 0, 0);
	med_x = ((bloc_coord.x + (bloc_coord.x + bloc_size)) / 2);
	med_y = ((bloc_coord.y + (bloc_coord.y + bloc_size)) / 2);
	if (coord.x < med_x)
		newcoord.x = bloc_coord.x;
	else if (coord.x >= med_x)
		newcoord.x = bloc_coord.x + bloc_size;
	if (coord.y < med_y)
		newcoord.y = bloc_coord.y;
	else if (coord.y >= med_y)
		newcoord.y = bloc_coord.y + bloc_size;
	return (newcoord);
}
