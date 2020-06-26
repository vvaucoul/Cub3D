/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:36:40 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 15:56:23 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
** Angle conversion, degrees, radians.
*/

float		ft_rad_to_deg(float angle_deg)
{
	return (angle_deg * 180 / M_PI);
}

float		ft_deg_to_rad(float angle_deg)
{
	return (angle_deg * (M_PI / 180));
}
