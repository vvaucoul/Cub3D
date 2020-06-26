/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:53:23 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/18 20:00:26 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Set variables when a key is pressed
*/

static void		movement_keys(int key, t_game *game)
{
	if (key == KEY_Z)
		game->input.move_forward = TRUE;
	else if (key == KEY_S)
		game->input.move_backward = TRUE;
	if (key == ARROW_LEFT)
		game->input.rotate_left = TRUE;
	else if (key == ARROW_RIGHT)
		game->input.rotate_right = TRUE;
	if (key == KEY_A)
		game->input.move_left = TRUE;
	else if (key == KEY_D)
		game->input.move_right = TRUE;
}

static void		ui_keys(int key, t_game *game)
{
	if (key == KEY_ESCAPE)
		quit_game(game);
	else if (key == KEY_HELP)
	{
		if (game->input.draw_help == FALSE)
			game->input.draw_help = TRUE;
		else
			game->input.draw_help = FALSE;
		draw_screen(game);
	}
	else if (key == KEY_TEXTURE)
	{
		if (game->input.draw_textures == FALSE)
			game->input.draw_textures = TRUE;
		else
			game->input.draw_textures = FALSE;
		draw_screen(game);
	}
}

static void		player_keys(int key, t_game *game)
{
	if (key == KEY_SPRINT)
		game->input.player_speed = 0.1;
}

int				key_pressed(int key, t_game *game)
{
	movement_keys(key, game);
	ui_keys(key, game);
	player_keys(key, game);
	return (0);
}
