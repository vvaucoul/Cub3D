/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:49:18 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/20 20:08:45 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Sprite casting
**	Draw sprite before walls
*/

static int		init_sprite_casting(t_game *game, int i)
{
	game->a_sray.sprite_x = game->sprites[game->a_sray.sprite_order[i]].pos.x
	- game->cam.pos.x - SPRITE_DECAL;
	game->a_sray.sprite_y = game->sprites[game->a_sray.sprite_order[i]].pos.y
	- game->cam.pos.y + SPRITE_DECAL;
	game->a_sray.inv_det = 1.0 / (game->a_ray.plane_x * game->a_ray.dir_y
	- game->a_ray.dir_x * game->a_ray.plane_y);
	game->a_sray.transform_x = game->a_sray.inv_det * (game->a_ray.dir_y
	* game->a_sray.sprite_x - game->a_ray.dir_x * game->a_sray.sprite_y);
	game->a_sray.transform_y = game->a_sray.inv_det * (-game->a_ray.plane_y
	* game->a_sray.sprite_x + game->a_ray.plane_x * game->a_sray.sprite_y);
	game->a_sray.sprite_screen_x = (int)(game->window.w_res.x / 2)
	* (1 + game->a_sray.transform_x
	/ game->a_sray.transform_y);
	game->a_sray.v_move_screen = (VMOVE / game->a_sray.transform_y);
	return (0);
}

static void		apply_sprite_color(t_game *game, int i, int y, t_vector2d tex)
{
	ft_memcpy(game->pixel.img_data + 4 * game->window.w_res.x
	* y + game->a_sray.stripe
	* 4, &game->sprites[game->a_sray.sprite_order[i]].data[tex.y %
	DEFAULT_TEX_HEIGHT * game->sprites
	[game->a_sray.sprite_order[i]].sizel +
	tex.x % DEFAULT_TEX_WIDTH * game->sprites
	[game->a_sray.sprite_order[i]].bpp / 8], sizeof(int));
}

static int		draw_sprite_line(t_game *game, t_vector2d tex, int i)
{
	int y;
	int sprite_color;
	int	d;

	y = game->a_sray.draw_start_y;
	while (y < game->a_sray.draw_end_y)
	{
		d = (y - game->a_sray.v_move_screen)
		* 256 - game->window.w_res.y * 128 + game->a_sray.sprite_height * 128;
		tex.y = ((d * DEFAULT_TEX_HEIGHT) / game->a_sray.sprite_height) / 256;
		sprite_color = game->sprites[game->a_sray.sprite_order[i]].data
		[tex.y % DEFAULT_TEX_HEIGHT
		* game->sprites[game->a_sray.sprite_order[i]].sizel
		+ tex.x % DEFAULT_TEX_WIDTH
		* game->sprites[game->a_sray.sprite_order[i]].bpp
		/ 8];
		if (sprite_color != -120)
			apply_sprite_color(game, i, y, tex);
		++y;
	}
	return (0);
}

static int		draw_sprite(t_game *game, int i)
{
	int tex_x;
	int	tex_y;

	tex_x = (int)(256 * (game->a_sray.stripe - (-game->a_sray.sprite_width / 2 +
	game->a_sray.sprite_screen_x)) * DEFAULT_TEX_WIDTH
	/ game->a_sray.sprite_width) / 256;
	tex_y = 0;
	if (game->a_sray.transform_y > 0 && game->a_sray.stripe > 0 &&
		game->a_sray.stripe < game->window.w_res.x && game->a_sray.transform_y
		< game->a_sray.zbuffer[game->a_sray.stripe])
	{
		draw_sprite_line(game, (t_vector2d){tex_x, tex_y}, i);
	}
	return (0);
}

int				spritecasting(t_game *game)
{
	int i;

	i = 0;
	set_sprite_order(game, i);
	renew_sprite_order(game);
	while (i < game->file.n_sprites)
	{
		init_sprite_casting(game, i);
		set_sprite_size(game);
		game->a_sray.stripe = game->a_sray.draw_start_x;
		while (game->a_sray.stripe < game->a_sray.draw_end_x)
		{
			draw_sprite(game, i);
			++game->a_sray.stripe;
		}
		++i;
	}
	return (0);
}
