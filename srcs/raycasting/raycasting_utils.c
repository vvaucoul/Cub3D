/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:29:44 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 17:30:21 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Raycasting utils
**	usefull functions to the raycasting function
*/

void			get_wall_hit(t_game *game)
{
	if ((game->a_ray.wall_side % 2) == 0)
		game->a_ray.wall_x = game->a_ray.ray_pos_x + game->a_ray.wall_len *
		game->a_ray.ray_dir_y;
	else
		game->a_ray.wall_x = game->a_ray.ray_pos_x + game->a_ray.wall_len *
		game->a_ray.ray_dir_x;
	game->a_ray.wall_x -= floor(game->a_ray.wall_x);
}

void			get_line_to_draw(t_game *game)
{
	if ((game->a_ray.wall_side % 2) == 0)
		game->a_ray.wall_len = fabs((game->a_ray.map_x - game->a_ray.ray_pos_x +
		(1 - game->a_ray.ray_step_x) / 2) / game->a_ray.ray_dir_x);
	else
		game->a_ray.wall_len = fabs((game->a_ray.map_y - game->a_ray.ray_pos_y +
		(1 - game->a_ray.ray_step_y) / 2) / game->a_ray.ray_dir_y);
	game->a_ray.wall_height = abs((int)(game->window.w_res.y
	/ game->a_ray.wall_len));
	game->a_ray.draw_start = (-game->a_ray.wall_height / 2
	+ game->window.w_res.y / 2);
	if (game->a_ray.draw_start < 0)
		game->a_ray.draw_start = 0;
	game->a_ray.draw_end = (game->a_ray.wall_height / 2
	+ game->window.w_res.y / 2);
	if (game->a_ray.draw_end >= game->window.w_res.y)
		game->a_ray.draw_end = game->window.w_res.y - 1;
}

void			ray_step(t_game *game)
{
	while (game->a_ray.wall_hit == 0)
	{
		if (game->a_ray.wall_dist_x < game->a_ray.wall_dist_y)
		{
			game->a_ray.wall_dist_x += game->a_ray.dist2_mur_x;
			game->a_ray.map_x += game->a_ray.ray_step_x;
			if (game->a_ray.ray_dir_x < 0)
				game->a_ray.wall_side = 2;
			else
				game->a_ray.wall_side = 0;
		}
		else
		{
			game->a_ray.wall_dist_y += game->a_ray.dist2_mur_y;
			game->a_ray.map_y += game->a_ray.ray_step_y;
			if (game->a_ray.ray_dir_y < 0)
				game->a_ray.wall_side = 1;
			else
				game->a_ray.wall_side = 3;
		}
		if (game->map.map[game->a_ray.map_x][game->a_ray.map_y] == '1')
			game->a_ray.wall_hit = 1;
	}
}

void			start_ray(t_game *game)
{
	game->a_ray.camera_x = 2 * game->a_ray.x / (float)game->window.w_res.x - 1;
	game->a_ray.ray_pos_x = game->cam.pos.x;
	game->a_ray.ray_pos_y = game->cam.pos.y;
	game->a_ray.ray_dir_x = game->a_ray.dir_x + game->a_ray.plane_x *
	game->a_ray.camera_x;
	game->a_ray.ray_dir_y = game->a_ray.dir_y + game->a_ray.plane_y *
	game->a_ray.camera_x;
	game->a_ray.map_x = (int)game->a_ray.ray_pos_x;
	game->a_ray.map_y = (int)game->a_ray.ray_pos_y;
	game->a_ray.dist2_mur_x = sqrt(1 + (game->a_ray.ray_dir_y
	* game->a_ray.ray_dir_y)
	/ (game->a_ray.ray_dir_x * game->a_ray.ray_dir_x));
	game->a_ray.dist2_mur_y = sqrt(1 + (game->a_ray.ray_dir_x
	* game->a_ray.ray_dir_x)
	/ (game->a_ray.ray_dir_y * game->a_ray.ray_dir_y));
	game->a_ray.wall_hit = 0;
}
