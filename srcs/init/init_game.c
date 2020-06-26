/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:01:40 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/20 20:11:31 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Initialize values in structure game
**	 - Default resolution : 1280*720
**	 - Default name : Cub3D
*/

static void				init_game_map(t_game *game)
{
	game->map.map = NULL;
	game->map.tmp_map = NULL;
	game->map.size_map = v_init_vector2d(0, 0);
}

static void				init_game_keys(t_game *game)
{
	if (!(game->file.all_keys = malloc(sizeof(char *) * (NB_KEYS * KEY_LEN))))
		malloc_error();
	if (!(game->file.keyfounds = malloc(sizeof(char *) * (NB_KEYS * KEY_LEN))))
		malloc_error();
	game->file.all_keys[0] = "R";
	game->file.all_keys[1] = "NO";
	game->file.all_keys[2] = "SO";
	game->file.all_keys[3] = "WE";
	game->file.all_keys[4] = "EA";
	game->file.all_keys[5] = "S";
	game->file.all_keys[6] = "F";
	game->file.all_keys[7] = "C";
	game->file.all_keys[8] = "1";
	game->file.all_keys[9] = NULL;
}

static void				init_game_values_input(t_game *game)
{
	game->input.move_forward = FALSE;
	game->input.move_backward = FALSE;
	game->input.move_right = FALSE;
	game->input.move_left = FALSE;
	game->input.rotate_left = FALSE;
	game->input.rotate_right = FALSE;
	game->input.rotate_up = FALSE;
	game->input.rotate_down = FALSE;
	game->input.draw_help = TRUE;
	game->input.draw_textures = FALSE;
	game->input.player_speed = 0.05;
}

static void				init_game_rays(t_game *game)
{
	game->a_ray.sf_dist = NULL;
	game->a_sray.zbuffer = NULL;
	game->a_sray.sprite_order = NULL;
	game->a_sray.sprite_distance = NULL;
}

t_bool					init_game_values(t_game *game)
{
	init_game_values_input(game);
	init_game_map(game);
	init_game_rays(game);
	if (!(init_game_values_next(game)))
		return (FALSE);
	init_game_keys(game);
	return (TRUE);
}
