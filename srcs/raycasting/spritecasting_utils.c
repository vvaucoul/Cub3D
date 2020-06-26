/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecasting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:02:36 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 18:36:14 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Functions usefull in the spritecasting
*/

int					set_sprite_order(t_game *game, int i)
{
	while (i < game->file.n_sprites)
	{
		game->a_sray.sprite_order[i] = i;
		game->a_sray.sprite_distance[i] = ((game->cam.pos.x -
		game->sprites[i].pos.x) *
		(game->cam.pos.x - game->sprites[i].pos.x)
		+ (game->cam.pos.y - game->sprites[i].pos.y) *
		(game->cam.pos.y - game->sprites[i].pos.y));
		++i;
	}
	return (0);
}

int					set_sprite_size(t_game *game)
{
	game->a_sray.sprite_height = abs((int)(game->window.w_res.y /
		game->a_sray.transform_y)) / VDIV;
	game->a_sray.draw_start_y = -game->a_sray.sprite_height
	/ 2 + game->window.w_res.y / 2 +
	game->a_sray.v_move_screen;
	if (game->a_sray.draw_start_y < 0)
		game->a_sray.draw_start_y = 0;
	game->a_sray.draw_end_y = game->a_sray.sprite_height
	/ 2 + game->window.w_res.y / 2 +
	game->a_sray.v_move_screen;
	if (game->a_sray.draw_end_y >= game->window.w_res.y)
		game->a_sray.draw_end_y = game->window.w_res.y - 1;
	game->a_sray.sprite_width = abs((int)(game->window.w_res.y /
	game->a_sray.transform_y)) / UDIV;
	game->a_sray.draw_start_x = -game->a_sray.sprite_height / 2 +
	game->a_sray.sprite_screen_x;
	if (game->a_sray.draw_start_x < 0)
		game->a_sray.draw_start_x = 0;
	game->a_sray.draw_end_x = game->a_sray.sprite_width / 2
	+ game->a_sray.sprite_screen_x;
	if (game->a_sray.draw_end_x >= game->window.w_res.x)
		game->a_sray.draw_end_x = game->window.w_res.x - 1;
	return (0);
}

static t_vector		get_sprites_dist(t_game *game, int i)
{
	return ((t_vector){((game->cam.pos.x -
	game->sprites[i].pos.x) * (game->cam.pos.x -
	game->sprites[i].pos.x)
	+ (game->cam.pos.y - game->sprites[i].pos.y) *
	(game->cam.pos.y - game->sprites[i].pos.y)),
	((game->cam.pos.x
	- game->sprites[i + 1].pos.x) *
	(game->cam.pos.x - game->sprites[i + 1].pos.x)
	+ (game->cam.pos.y - game->sprites[i + 1].pos.y) *
	(game->cam.pos.y - game->sprites[i + 1].pos.y)), 0});
}

static void			renew_sprite_order_while(t_game *game, t_bool *valid,
t_vector dsp)
{
	int			i;
	t_sprites	tmp;

	i = 0;
	while (i + 1 < game->file.n_sprites)
	{
		game->a_sray.sprite_distance[i] = get_sprites_dist(game, i).x;
		dsp.x = game->a_sray.sprite_distance[i];
		game->a_sray.sprite_distance[i + 1] = get_sprites_dist(game, i).y;
		dsp.y = game->a_sray.sprite_distance[i + 1];
		if (dsp.x < dsp.y)
		{
			tmp = game->sprites[i];
			game->sprites[i] = game->sprites[i + 1];
			game->sprites[i + 1] = tmp;
			valid[0] = FALSE;
		}
		++i;
	}
}

int					renew_sprite_order(t_game *game)
{
	t_bool		valid;
	int			i;
	float		dist_sprite_01;
	float		dist_sprite_02;

	valid = FALSE;
	while (!valid)
	{
		i = 0;
		valid = TRUE;
		dist_sprite_01 = 0.0;
		dist_sprite_02 = 0.0;
		renew_sprite_order_while(game, &valid,
		(t_vector){dist_sprite_01, dist_sprite_02, 0});
	}
	return (0);
}
