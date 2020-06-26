/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_get_forward_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:38:28 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 16:03:04 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
** Get forward vector by a rotation in Radian
*/

t_vector	v_get_forward_vector(t_vector actu_pos, float angle, float distance)
{
	actu_pos.x = distance * cos(angle) + actu_pos.x;
	actu_pos.y = distance * sin(angle) + actu_pos.y;
	return (actu_pos);
}
