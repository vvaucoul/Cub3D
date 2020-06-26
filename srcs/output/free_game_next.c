/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:22:30 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/20 16:58:59 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Next file to free game struct
*/

static void			free_game_rays(t_game *game)
{
	if (game->a_ray.sf_dist)
		free(game->a_ray.sf_dist);
	if (game->a_sray.zbuffer)
		free(game->a_sray.zbuffer);
	if (game->a_sray.sprite_order)
		free(game->a_sray.sprite_order);
	if (game->a_sray.sprite_distance)
		free(game->a_sray.sprite_distance);
}

static void			free_game_file_keys(t_game *game)
{
	int y;

	if (game->file.keyfounds)
	{
		y = 0;
		while (y < game->file.actu_key)
			free(game->file.keyfounds[y++]);
		free(game->file.keyfounds);
	}
	if (game->file.all_keys)
		free(game->file.all_keys);
}

static void			free_game_file(t_game *game)
{
	if (game->file.file)
		free(game->file.file);
	if (game->file.no_texture)
		free(game->file.no_texture);
	if (game->file.so_texture)
		free(game->file.so_texture);
	if (game->file.we_texture)
		free(game->file.we_texture);
	if (game->file.ea_texture)
		free(game->file.ea_texture);
	if (game->file.sprite)
		free(game->file.sprite);
	free_game_file_keys(game);
}

static void			free_game_textures(t_game *game)
{
	int i;

	i = 0;
	{
		if (game->textures)
		{
			while (i < DEFAULT_NB_TEXTURES)
				mlx_destroy_image(game->mlx.mlx, game->textures[i++].img);
		}
	}
}

void				free_game_next(t_game *game)
{
	free_game_file(game);
	free_game_rays(game);
	free_game_textures(game);
}
