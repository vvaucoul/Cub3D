/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_math.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:31:00 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 17:05:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Specials functions for the raycasting
*/

float		get_ray_distance(t_game *game)
{
	float dist;

	if (game->a_ray.wall_side % 2)
	{
		dist = (game->a_ray.ray_pos_y - game->cam.pos.y +
		(1.0 - game->a_ray.ray_step_y) / 2.0);
		return (fabs(dist / game->a_ray.ray_dir_y));
	}
	dist = (game->a_ray.ray_pos_x - game->cam.pos.x +
	(1.0 - game->a_ray.ray_step_x) / 2.0);
	return (fabs(dist / game->a_ray.ray_dir_x));
}

int			wall_direction(t_game *game)
{
	if (game->a_ray.wall_side % 2)
		return ((game->a_ray.ray_dir_y < 0) ? (ID_TEX_NORTH) : (ID_TEX_SOUTH));
	return ((game->a_ray.ray_dir_x < 0) ? (ID_TEX_WEST) : (ID_TEX_EAST));
}
