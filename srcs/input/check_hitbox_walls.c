/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hitbox_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:10:27 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 17:24:14 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Check collisions with walls
*/

t_bool			check_hit_box_forward_next(t_game *game, int dir)
{
	if (dir == 3)
	{
		if ((game->map.map[(int)(game->cam.pos.x - game->a_ray.dir_x
		* (game->input.player_speed + HIT_BOX_SIZE))]
		[(int)(game->cam.pos.y)] != '1'))
			return (TRUE);
	}
	else if (dir == 4)
	{
		if ((game->map.map[(int)(game->cam.pos.x)][
		(int)(game->cam.pos.y - game->a_ray.dir_y
		* (game->input.player_speed
		+ HIT_BOX_SIZE))] != '1'))
			return (TRUE);
	}
	return (FALSE);
}

t_bool			check_hit_box_forward(t_game *game, int dir)
{
	if (dir == 1)
	{
		if ((game->map.map[(int)(game->cam.pos.x + game->a_ray.dir_x *
		(game->input.player_speed + HIT_BOX_SIZE))]
		[(int)(game->cam.pos.y)] != '1'))
			return (TRUE);
	}
	else if (dir == 2)
	{
		if ((game->map.map[(int)(game->cam.pos.x)][
		(int)(game->cam.pos.y + game->a_ray.dir_y *
		(game->input.player_speed + HIT_BOX_SIZE))] != '1'))
			return (TRUE);
	}
	else if (check_hit_box_forward_next(game, dir) == TRUE)
		return (TRUE);
	return (FALSE);
}

t_bool			check_hit_box_right_next(t_game *game, int dir)
{
	if (dir == 3)
	{
		if ((game->map.map[(int)(game->cam.pos.x - game->a_ray.plane_x
		* ((game->input.player_speed * P_STRAFE) + HIT_BOX_SIZE))]
		[(int)(game->cam.pos.y)]
		!= '1'))
			return (TRUE);
	}
	else if (dir == 4)
	{
		if ((game->map.map[(int)(game->cam.pos.x)][
		(int)(game->cam.pos.y - game->a_ray.plane_y *
		((game->input.player_speed * P_STRAFE) + HIT_BOX_SIZE))] != '1'))
			return (TRUE);
	}
	return (FALSE);
}

t_bool			check_hit_box_right(t_game *game, int dir)
{
	if (dir == 1)
	{
		if ((game->map.map[(int)(game->cam.pos.x + game->a_ray.plane_x *
		((game->input.player_speed * P_STRAFE) + HIT_BOX_SIZE))]
		[(int)(game->cam.pos.y)]
		!= '1'))
			return (TRUE);
	}
	else if (dir == 2)
	{
		if ((game->map.map[(int)(game->cam.pos.x)][
		(int)(game->cam.pos.y + game->a_ray.plane_y *
		((game->input.player_speed * P_STRAFE) + HIT_BOX_SIZE))] != '1'))
			return (TRUE);
	}
	else if (check_hit_box_right_next(game, dir) == TRUE)
		return (TRUE);
	return (FALSE);
}
