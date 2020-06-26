/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:56:02 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 12:59:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Draw vertical line, textured or not
**	pos.x = start
**	pos.y = end
*/

int			draw_vertical_line_textured(t_game *game, int x, t_vector2d pos,
int id)
{
	static float x_wall = 0;

	if (game->a_ray.wall_side == 0 || game->a_ray.wall_side == 2)
		x_wall = game->a_ray.ray_pos_y +
		game->a_ray.wall_len * game->a_ray.ray_dir_y;
	else if (game->a_ray.wall_side == 1 || game->a_ray.wall_side == 3)
		x_wall = game->a_ray.ray_pos_x +
		game->a_ray.wall_len * game->a_ray.ray_dir_x;
	game->a_ray.tex_x = (int)(x_wall * (float)(64));
	if ((game->a_ray.wall_side == 0 || game->a_ray.wall_side == 2) &&
		game->a_ray.ray_dir_x > 0)
		game->a_ray.tex_x = 64 - game->a_ray.tex_x - 1;
	if ((game->a_ray.wall_side == 1 || game->a_ray.wall_side == 3) &&
		game->a_ray.ray_dir_y < 0)
		game->a_ray.tex_x = 64 - game->a_ray.tex_x - 1;
	game->a_ray.tex_x = abs(game->a_ray.tex_x);
	++pos.x;
	while (pos.x < pos.y)
	{
		put_pixel_texture(game, x, pos.x, id);
		++pos.x;
	}
	return (0);
}

int			draw_vertical_line(t_game *game, int x, t_vector2d pos, int color)
{
	draw_pixel(game, (t_vector2d){x, pos.x}, color);
	while (++pos.x < pos.y)
		draw_pixel(game, (t_vector2d){x, pos.x}, color);
	return (0);
}
