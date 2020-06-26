/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:53:29 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/21 17:18:21 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
** Display error message
** if fileerror is true, it display "Error\n" before
*/

void		malloc_error(void)
{
	write(OUTPUT_ERROR, ERROR_MALLOC, ft_strlen(ERROR_MALLOC));
	write(OUTPUT_ERROR, "\n", 1);
	exit(EXIT_FAILURE);
}

int			game_error(t_game *game, char *str, t_bool fileerror,
t_bool freeg)
{
	if (freeg)
		free_game(game);
	if (fileerror)
	{
		write(OUTPUT_ERROR, "Error\n", 6);
		write(OUTPUT_ERROR, str, ft_strlen(str));
		write(OUTPUT_ERROR, "\n", 1);
	}
	else
	{
		write(OUTPUT_ERROR, str, ft_strlen(str));
		write(OUTPUT_ERROR, "\n", 1);
	}
	exit(EXIT_FAILURE);
}
