/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:55:35 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/21 17:04:40 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Initialise default textures
**	0 = N | 1 = S | 2 = O | 3 = E
**	If texture direction is not found, it is replaced by default texture
*/

static char			*get_texturebyindex(t_game *game, int index)
{
	if (index == ID_TEX_NORTH)
	{
		if (game->file.no_texture)
			return (game->file.no_texture);
	}
	else if (index == ID_TEX_SOUTH)
	{
		if (game->file.so_texture)
			return (game->file.so_texture);
	}
	else if (index == ID_TEX_WEST)
	{
		if (game->file.we_texture)
			return (game->file.we_texture);
	}
	else if (index == ID_TEX_EAST)
	{
		if (game->file.ea_texture)
			return (game->file.ea_texture);
	}
	return (DEFAULT_TEXTURE);
}

int					load_textures(t_game *game)
{
	t_vector2d	size;
	int			i;

	if (!(game->textures = (t_texture *)malloc(sizeof(t_texture) *
		(DEFAULT_NB_TEXTURES + 1))))
		malloc_error();
	i = 0;
	while (i < DEFAULT_NB_TEXTURES)
	{
		size = v_init_vector2d(64, 64);
		if (!(game->textures[i].img = mlx_xpm_file_to_image(game->mlx.mlx,
		get_texturebyindex(game, i), &size.x, &size.y)))
			game_error(game, ERROR_TEXTURE_PATH, TRUE, TRUE);
		game->textures[i].data = mlx_get_data_addr(game->textures[i].img,
		&game->textures[i].bpp, &game->textures[i].sizel,
		&game->textures[i].endian);
		game->textures[i].size = size;
		++i;
	}
	return (0);
}
