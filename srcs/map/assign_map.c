/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 16:54:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/20 19:29:22 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Assign map to char ** in game struct [game->map.map]
*/

static char			**malloc_map(t_vector2d size)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (size.x * size.y + 1))))
		malloc_error();
	while (i < size.y)
	{
		if (!(map[i] = malloc(sizeof(char) * size.x + 1)))
			malloc_error();
		++i;
	}
	map[i] = NULL;
	return (map);
}

static t_vector2d	get_mapsize(char *str)
{
	t_vector2d	size;
	int			max_x;
	int			i;

	size = v_init_vector2d(0, 0);
	max_x = 0;
	i = 0;
	while (str[i])
	{
		++size.x;
		if (is_eol(str[i]))
		{
			if (size.x > max_x)
				max_x = size.x;
			size.x = 0;
			++size.y;
		}
		++i;
	}
	return ((t_vector2d){max_x - 1, size.y});
}

static int			set_map(t_game *game)
{
	t_vector2d	coord;
	int			i;

	i = 0;
	coord = v_init_vector2d(0, 0);
	while (game->map.tmp_map[i])
	{
		game->map.map[coord.y][coord.x] = game->map.tmp_map[i];
		++coord.x;
		if (is_eol(game->map.tmp_map[i]))
		{
			coord.x = 0;
			++coord.y;
		}
		++i;
	}
	return (0);
}

static t_bool		valid_size_map(t_game *game)
{
	if (game->map.size_map.x < MIN_MAP_SIZE
	|| game->map.size_map.y < MIN_MAP_SIZE)
		return (FALSE);
	return (TRUE);
}

int					assign_map(t_game *game)
{
	if (!game->map.tmp_map)
		game_error(game, ERROR_EMPTY_MAP, TRUE, TRUE);
	game->map.size_map = get_mapsize(game->map.tmp_map);
	if (!(valid_size_map(game)))
		game_error(game, ERROR_MAP_SMALL, TRUE, TRUE);
	game->map.map = malloc_map(get_mapsize(game->map.tmp_map));
	set_map(game);
	check_map(game);
	return (0);
}
