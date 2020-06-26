/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:05:28 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/20 19:25:02 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Check arguments gived by the main function
**	then, check if the map has ".cub" in format
*/

int		check_args(t_game *game, int argc, char **argv)
{
	if (argc <= 1)
		game_error(game, ERROR_ARGUMENTS_UNDER, FALSE, TRUE);
	else if (argc >= 4)
		game_error(game, ERROR_ARGUMENTS_SUP, FALSE, TRUE);
	if (argc == 3 && !(ft_strcmp(argv[2], GAME_SAVE_ARGUMENT)))
		game->file.screenshot = TRUE;
	else if (argc == 3)
		game_error(game, ERROR_ARGUMENTS_INVALID, FALSE, TRUE);
	if ((ft_has_format(argv[1], GAME_FILE_FORMAT)) != 1)
		game_error(game, ERROR_MAP_FORMAT, FALSE, TRUE);
	return (0);
}
