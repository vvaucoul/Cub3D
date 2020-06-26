/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:10:27 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/18 19:59:50 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Call functions to check hitbox
*/

t_bool			hit_box_forward(t_game *game, int dir)
{
	if (check_hit_box_forward(game, dir))
		return (TRUE);
	else
		return (FALSE);
}

t_bool			hit_box_right(t_game *game, int dir)
{
	if (check_hit_box_right(game, dir))
		return (TRUE);
	else
		return (FALSE);
}
