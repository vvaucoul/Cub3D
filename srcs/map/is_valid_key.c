/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:11:47 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/10/28 15:57:29 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Check if key found in map line is valid
**  My keys and subject keys
*/

t_bool				add_key_to_dic(t_game *game, char *key)
{
	if (ft_isdigit(key[0]))
		return (FALSE);
	if (!(game->file.keyfounds[game->file.actu_key] = ft_strdup(key)))
		malloc_error();
	game->file.keyfounds[game->file.actu_key + 1] = NULL;
	++game->file.actu_key;
	return (FALSE);
}

static t_bool		is_a_key(t_game *game, char *key)
{
	int		i;

	i = 0;
	while (i < NB_KEYS)
	{
		if (!ft_strcmp(game->file.all_keys[i], key))
			return (TRUE);
		++i;
	}
	return (FALSE);
}

t_bool				is_valid_key(t_game *game, char *key)
{
	int i;

	i = 0;
	if (ft_isdigit(key[0]))
		return (TRUE);
	if (!(is_a_key(game, key)))
		game_error(game, ERROR_INVALID_KEY, TRUE, TRUE);
	while (i < game->file.actu_key)
	{
		if (ft_strcmp(game->file.keyfounds[i], key) == 0)
			game_error(game, ERROR_DOUBLON_FOUND, TRUE, TRUE);
		++i;
	}
	return (TRUE);
}
