/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:44:45 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 15:53:47 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
** Does the variable is between max and min ?
*/

t_bool		ft_clamped(t_vector min, t_vector max, float value)
{
	if ((value >= min.x && value < max.x) &&
		(value >= min.y && value < max.y))
		return (TRUE);
	return (FALSE);
}
