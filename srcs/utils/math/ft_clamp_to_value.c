/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp_to_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:39:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 15:50:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
**	Set value to a range value
** 	Exemple : 27 in range 5 = 25.
**	We need all 5 per 5 values
*/

int		ft_clamp_to_value(int value, int range)
{
	return (value - (value % range));
}
