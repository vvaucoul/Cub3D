/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:44:14 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/20 19:29:12 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Parse map file
**	Place characters readed in the "tmp map" variable
*/

static int			init_map(t_game *game)
{
	if (!(game->map.tmp_map = (char *)malloc(sizeof(char) * 1)))
		malloc_error();
	game->map.tmp_map[0] = '\0';
	game->map.size_map.x = 0;
	game->map.size_map.y = 0;
	return (0);
}

static t_bool		is_valid_map_line(char *str)
{
	t_bool		valid;
	int			i;
	int			j;

	i = 0;
	while (str[i])
	{
		j = 0;
		valid = FALSE;
		while (ALL_CHAR_IN_MAP_VALID[j])
		{
			if (ALL_CHAR_IN_MAP_VALID[j] == str[i])
				valid = TRUE;
			++j;
		}
		if (valid == FALSE)
			return (FALSE);
		++i;
	}
	return (valid);
}

int					parse_map(t_game *game, char *str)
{
	static t_bool	init = FALSE;
	char			*map_without_spaces;
	char			*previous_tmp_map;

	if (!init)
	{
		init_map(game);
		init = TRUE;
	}
	map_without_spaces = ft_removespaces(str);
	if (!(is_valid_map_line(map_without_spaces)))
		game_error(game, ERROR_INVALID_MAP_KEY, TRUE, TRUE);
	previous_tmp_map = ft_strdup(game->map.tmp_map);
	free(game->map.tmp_map);
	game->map.tmp_map = ft_strjoin(previous_tmp_map, map_without_spaces);
	free(map_without_spaces);
	free(previous_tmp_map);
	return (0);
}
