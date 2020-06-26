/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:17:07 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/22 15:26:21 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
** Fonction raycasting
*/

static void		ray_draw_line_next(t_game *game)
{
	if (game->a_ray.wall_side == 3)
	{
		if (game->input.draw_textures == FALSE)
			draw_vertical_line(game, game->a_ray.x,
			(t_vector2d){game->a_ray.draw_start,
			game->a_ray.draw_end}, COLOR_SOUTH);
		else
			draw_vertical_line_textured(game, game->a_ray.x,
			(t_vector2d){game->a_ray.draw_start,
			game->a_ray.draw_end}, ID_TEX_SOUTH);
	}
	else
	{
		if (game->input.draw_textures == FALSE)
			draw_vertical_line(game, game->a_ray.x,
			(t_vector2d){game->a_ray.draw_start,
			game->a_ray.draw_end}, COLOR_EAST);
		else
			draw_vertical_line_textured(game, game->a_ray.x,
			(t_vector2d){game->a_ray.draw_start,
			game->a_ray.draw_end}, ID_TEX_EAST);
	}
}

static void		ray_draw_line(t_game *game)
{
	if (game->a_ray.wall_side == 1)
	{
		if (game->input.draw_textures == FALSE)
			draw_vertical_line(game, game->a_ray.x,
			(t_vector2d){game->a_ray.draw_start,
			game->a_ray.draw_end}, COLOR_NORTH);
		else
			draw_vertical_line_textured(game, game->a_ray.x,
			(t_vector2d){game->a_ray.draw_start,
			game->a_ray.draw_end}, ID_TEX_NORTH);
	}
	else if (game->a_ray.wall_side == 2)
	{
		if (game->input.draw_textures == FALSE)
			draw_vertical_line(game, game->a_ray.x,
			(t_vector2d){game->a_ray.draw_start,
			game->a_ray.draw_end}, COLOR_WEST);
		else
			draw_vertical_line_textured(game, game->a_ray.x,
			(t_vector2d){game->a_ray.draw_start,
			game->a_ray.draw_end}, ID_TEX_WEST);
	}
	else
		ray_draw_line_next(game);
}

int				raycasting(t_game *game)
{
	game->a_ray.x = 0;
	init_raycasting(game);
	while (game->a_ray.x < game->window.w_res.x)
	{
		start_ray(game);
		ray_dir(game);
		ray_step(game);
		get_line_to_draw(game);
		get_wall_hit(game);
		game->a_ray.distance = get_ray_distance(game);
		game->a_ray.direction = wall_direction(game);
		draw_sky(game);
		ray_draw_line(game);
		draw_floor(game);
		++game->a_ray.x;
		game->a_sray.zbuffer[game->a_ray.x] = game->a_ray.wall_len;
	}
	spritecasting(game);
	return (0);
}
