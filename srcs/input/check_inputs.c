/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:53:23 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/21 17:18:13 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Check inputs
**	And draw window only if the player move
*/

int				quit_game(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
}

static void		movement_keys(t_game *game)
{
	if (game->input.move_forward && !game->input.move_backward)
		forward_input(game, TRUE);
	else if (game->input.move_backward && !game->input.move_forward)
		forward_input(game, FALSE);
	if (game->input.move_left && !game->input.move_right)
		right_input(game, FALSE);
	else if (game->input.move_right && !game->input.move_left)
		right_input(game, TRUE);
}

static void		rotation_keys(t_game *game)
{
	if (game->input.rotate_right && !game->input.rotate_left)
		yaw_input(game, TRUE);
	else if (game->input.rotate_left && !game->input.rotate_right)
		yaw_input(game, FALSE);
}

int				checkinputs(t_game *game)
{
	movement_keys(game);
	rotation_keys(game);
	if ((game->input.move_forward) ||
	(game->input.move_backward) ||
	(game->input.move_left) ||
	(game->input.move_right) ||
	(game->input.rotate_left) ||
	(game->input.rotate_right) ||
	(game->input.rotate_up) ||
	(game->input.rotate_down))
		draw_screen(game);
	return (0);
}
