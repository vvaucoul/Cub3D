/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 20:22:47 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 17:24:56 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Movement player
**	Include Wall collision to prevent segfault
*/

int		yaw_input_neg(t_game *game)
{
	float	old_dirx;
	float	old_plane_x;

	old_dirx = game->a_ray.dir_x;
	game->a_ray.dir_x = game->a_ray.dir_x
	* cos(ROTATION_SPEED) - game->a_ray.dir_y
	* sin(ROTATION_SPEED);
	game->a_ray.dir_y = old_dirx * sin(ROTATION_SPEED)
	+ game->a_ray.dir_y
	* cos(ROTATION_SPEED);
	old_plane_x = game->a_ray.plane_x;
	game->a_ray.plane_x = game->a_ray.plane_x * cos(ROTATION_SPEED)
	- game->a_ray.plane_y * sin(ROTATION_SPEED);
	game->a_ray.plane_y = old_plane_x * sin(ROTATION_SPEED)
	+ game->a_ray.plane_y
	* cos(ROTATION_SPEED);
	game->cam.angle += 4;
	if (game->cam.angle >= 360)
		game->cam.angle -= 360;
	return (0);
}

int		yaw_input(t_game *game, t_bool input)
{
	float	old_dirx;
	float	old_plane_x;

	if (input)
	{
		old_dirx = game->a_ray.dir_x;
		game->a_ray.dir_x = game->a_ray.dir_x * cos(-ROTATION_SPEED)
		- game->a_ray.dir_y * sin(-ROTATION_SPEED);
		game->a_ray.dir_y = old_dirx * sin(-ROTATION_SPEED) + game->a_ray.dir_y
		* cos(-ROTATION_SPEED);
		old_plane_x = game->a_ray.plane_x;
		game->a_ray.plane_x = game->a_ray.plane_x * cos(-ROTATION_SPEED)
		- game->a_ray.plane_y * sin(-ROTATION_SPEED);
		game->a_ray.plane_y = old_plane_x * sin(-ROTATION_SPEED)
		+ game->a_ray.plane_y * cos(-ROTATION_SPEED);
		game->cam.angle -= 4;
		if (game->cam.angle < 0)
			game->cam.angle += 360;
	}
	else
		yaw_input_neg(game);
	return (0);
}

int		forward_input(t_game *game, t_bool forward)
{
	if (forward)
	{
		if (hit_box_forward(game, 1))
			game->cam.pos.x += game->a_ray.dir_x * game->input.player_speed;
		if (hit_box_forward(game, 2))
			game->cam.pos.y += game->a_ray.dir_y * game->input.player_speed;
	}
	else
	{
		if (hit_box_forward(game, 3))
			game->cam.pos.x -= game->a_ray.dir_x * game->input.player_speed;
		if (hit_box_forward(game, 4))
			game->cam.pos.y -= game->a_ray.dir_y * game->input.player_speed;
	}
	return (0);
}

int		right_input(t_game *game, t_bool right)
{
	if (right)
	{
		if (hit_box_right(game, 1))
			game->cam.pos.x += (game->a_ray.plane_x
			* game->input.player_speed * P_STRAFE);
		if (hit_box_right(game, 2))
			game->cam.pos.y += (game->a_ray.plane_y
			* game->input.player_speed * P_STRAFE);
	}
	else
	{
		if (hit_box_right(game, 3))
			game->cam.pos.x -= (game->a_ray.plane_x
			* game->input.player_speed * P_STRAFE);
		if (hit_box_right(game, 4))
			game->cam.pos.y -= (game->a_ray.plane_y
			* game->input.player_speed * P_STRAFE);
	}
	return (0);
}
