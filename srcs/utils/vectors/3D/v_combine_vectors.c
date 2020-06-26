/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_combine_vectors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:24:54 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 16:02:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
** A simple addition between 2 vectors
*/

t_vector	v_combine_vectors(t_vector base, t_vector add)
{
	base.x += add.x;
	base.y += add.y;
	base.z += add.z;
	return (base);
}
