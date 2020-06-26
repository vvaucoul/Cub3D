/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_initvector2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 16:57:08 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 16:04:16 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
**	Init vector2D
*/

t_vector2d	v_init_vector2d(int x, int y)
{
	return ((t_vector2d){x, y});
}
