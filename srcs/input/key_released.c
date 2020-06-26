/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_released.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:53:23 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/18 19:59:56 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		movement_keys(int key, t_game *game)
{
	if (key == KEY_Z)
		game->input.move_forward = FALSE;
	else if (key == KEY_S)
		game->input.move_backward = FALSE;
	if (key == ARROW_LEFT)
		game->input.rotate_left = FALSE;
	else if (key == ARROW_RIGHT)
		game->input.rotate_right = FALSE;
	if (key == KEY_A)
		game->input.move_left = FALSE;
	else if (key == KEY_D)
		game->input.move_right = FALSE;
}

static void		player_keys(int key, t_game *game)
{
	if (key == KEY_SPRINT)
		game->input.player_speed = 0.05;
}

int				key_released(int key, t_game *game)
{
	movement_keys(key, game);
	player_keys(key, game);
	return (0);
}
