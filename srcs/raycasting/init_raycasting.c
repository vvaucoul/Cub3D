/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:38:40 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/20 20:00:31 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Init raycasting by cam angle
**	Init spritecasting
*/

static void				init_dir_next(t_game *game)
{
	if (game->cam.angle == 270)
	{
		game->a_ray.dir_x = 0;
		game->a_ray.dir_y = 1;
		game->a_ray.plane_x = 0.66;
		game->a_ray.plane_y = 0;
	}
	else if (game->cam.angle == 180)
	{
		game->a_ray.dir_x = 1;
		game->a_ray.dir_y = 0;
		game->a_ray.plane_x = 0;
		game->a_ray.plane_y = -0.66;
	}
}

static void				init_dir(t_game *game)
{
	if (game->cam.angle == 90)
	{
		game->a_ray.dir_x = 0;
		game->a_ray.dir_y = -1;
		game->a_ray.plane_x = -0.66;
		game->a_ray.plane_y = 0;
	}
	else if (game->cam.angle == 0)
	{
		game->a_ray.dir_x = -1;
		game->a_ray.dir_y = 0;
		game->a_ray.plane_x = 0;
		game->a_ray.plane_y = 0.66;
	}
	else
		init_dir_next(game);
}

int						init_raycasting(t_game *game)
{
	static t_bool init = FALSE;

	if (!init)
	{
		init_dir(game);
		if (!(game->a_ray.sf_dist = malloc(sizeof(float)
		* game->window.w_res.y + 1)))
			malloc_error();
		if (!(game->a_sray.zbuffer = malloc(sizeof(float)
		* (game->window.w_res.x * game->window.w_res.y) + 1)))
			malloc_error();
		if (!(game->a_sray.sprite_order = malloc(sizeof(int) *
		game->file.n_sprites + 1)))
			malloc_error();
		if (!(game->a_sray.sprite_distance = malloc(sizeof(float) *
		game->file.n_sprites + 1)))
			malloc_error();
		init = TRUE;
	}
	return (0);
}
