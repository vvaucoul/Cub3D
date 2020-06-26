/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:01:40 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/20 16:43:56 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Initialize values in structure game
**	- Default resolution : 1280*720
**	- Default name : Cub3D
*/

static void				init_game_structs(t_game *game)
{
	game->textures = NULL;
	game->sprites = NULL;
}

static void				init_game_mlx(t_game *game)
{
	game->mlx.mlx = NULL;
	game->mlx.window = NULL;
	game->mlx.mlx_loaded = FALSE;
}

static void				init_game_window(t_game *game)
{
	game->window.w_res = v_init_vector2d(1280, 720);
	game->window.window_name = "Cub3D";
}

static void				init_game_file(t_game *game)
{
	game->file.fd = 0;
	game->file.file = NULL;
	game->file.no_texture = NULL;
	game->file.so_texture = NULL;
	game->file.we_texture = NULL;
	game->file.ea_texture = NULL;
	game->file.sprite = NULL;
	game->file.top_color = 0x66CCFF;
	game->file.floor_color = 0x333333;
	game->file.n_sprites = 0;
	game->file.n_tex = 0;
	game->file.keyfounds = NULL;
	game->file.actu_key = 0;
	game->file.all_keys = NULL;
	game->file.screenshot = FALSE;
}

t_bool					init_game_values_next(t_game *game)
{
	init_game_file(game);
	init_game_window(game);
	init_game_mlx(game);
	init_game_structs(game);
	return (TRUE);
}
