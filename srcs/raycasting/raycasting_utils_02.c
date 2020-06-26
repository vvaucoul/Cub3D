/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_02.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:29:44 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 17:33:37 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Raycasting utils 02
**	next file which include usefull functions to the raycasting function
*/

void			ray_dir_next(t_game *game)
{
	if (game->a_ray.ray_dir_y < 0)
	{
		game->a_ray.ray_step_y = -1;
		game->a_ray.wall_dist_y = (game->a_ray.ray_pos_y - game->a_ray.map_y) *
		game->a_ray.dist2_mur_y;
	}
	else
	{
		game->a_ray.ray_step_y = 1;
		game->a_ray.wall_dist_y = (game->a_ray.map_y + 1.0
		- game->a_ray.ray_pos_y) *
		game->a_ray.dist2_mur_y;
	}
}

void			ray_dir(t_game *game)
{
	if (game->a_ray.ray_dir_x < 0)
	{
		game->a_ray.ray_step_x = -1;
		game->a_ray.wall_dist_x = (game->a_ray.ray_pos_x - game->a_ray.map_x) *
		game->a_ray.dist2_mur_x;
	}
	else
	{
		game->a_ray.ray_step_x = 1;
		game->a_ray.wall_dist_x = (game->a_ray.map_x + 1.0
		- game->a_ray.ray_pos_x) *
		game->a_ray.dist2_mur_x;
	}
	ray_dir_next(game);
}
