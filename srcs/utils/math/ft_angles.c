/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:40:27 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 15:55:10 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
** Manage angles (cos, sin, angle in radian)
*/

float	ft_dcos(float angle_deg)
{
	return (cos(ft_deg_to_rad(angle_deg)));
}

float	ft_dsin(float angle_deg)
{
	return (sin(ft_deg_to_rad(angle_deg)));
}

float	ft_vangle(float v1, float v2)
{
	return (atanf(v2 / v1));
}
