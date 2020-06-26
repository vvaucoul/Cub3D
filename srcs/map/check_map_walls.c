/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:00:02 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/21 15:15:28 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
** Check map borders
** All corners and walls should be '1'
*/

static t_bool		check_top(t_game *game)
{
	int i;

	i = 0;
	while (!is_eol(game->map.map[0][i]))
	{
		if (game->map.map[0][i] != '1')
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static t_bool		check_left(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map.size_map.y)
	{
		if (game->map.map[i][0] != '1')
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static t_bool		check_right(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map.size_map.y)
	{
		if (game->map.map[i][game->map.size_map.x - 1] != '1')
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static t_bool		check_bottom(t_game *game)
{
	int i;

	i = 0;
	while (!is_eol(game->map.map[game->map.size_map.y - 1][i]))
	{
		if (game->map.map[game->map.size_map.y - 1][i] != '1')
			return (FALSE);
		++i;
	}
	return (TRUE);
}

int					check_map(t_game *game)
{
	if (!(check_top(game)))
		game_error(game, ERROR_WRONG_TOP_WALL, TRUE, TRUE);
	if (!(check_left(game)))
		game_error(game, ERROR_WRONG_LEFT_WALL, TRUE, TRUE);
	if (!(check_right(game)))
		game_error(game, ERROR_WRONG_RIGHT_WALL, TRUE, TRUE);
	if (!(check_bottom(game)))
		game_error(game, ERROR_WRONG_BOTTOM_WALL, TRUE, TRUE);
	return (0);
}
