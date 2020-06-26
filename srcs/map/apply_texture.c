/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:03:52 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 22:46:19 by vintz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Apply texture with direction
*/

int		apply_texture(t_game *game, char *texture, char *sw)
{
	if ((ft_strcmp(sw, "NO")) == 0)
		game->file.no_texture = ft_strdup(texture);
	else if ((ft_strcmp(sw, "SO")) == 0)
		game->file.so_texture = ft_strdup(texture);
	else if ((ft_strcmp(sw, "WE")) == 0)
		game->file.we_texture = ft_strdup(texture);
	else if ((ft_strcmp(sw, "EA")) == 0)
		game->file.ea_texture = ft_strdup(texture);
	free(texture);
	return (0);
}
