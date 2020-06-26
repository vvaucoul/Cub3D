/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:34:07 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 17:33:50 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		put_pixel_texture(t_game *game, int x, int y, int id)
{
	int color;

	if (x < game->window.w_res.x && y < game->window.w_res.y && x > 0 && y > 0)
	{
		game->a_ray.tex_y = abs((((y * 256 - game->window.w_res.y * 128 +
		game->a_ray.wall_height * 128) * 64) / game->a_ray.wall_height) / 256);
		color = game->textures[id].data[game->a_ray.tex_y %
		game->textures[id].size.y
		* game->textures[id].sizel + game->a_ray.tex_x %
		game->textures[id].size.x *
		game->textures[id].bpp / 8];
		if (color != -120)
		{
			ft_memcpy(game->pixel.img_data + 4
			* game->window.w_res.x * y + x * 4,
			&game->textures[id].data[game->a_ray.tex_y %
			game->textures[id].size.y
			* game->textures[id].sizel + game->a_ray.tex_x %
			game->textures[id].size.x *
			game->textures[id].bpp / 8], sizeof(int));
		}
	}
}
