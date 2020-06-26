/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:56:22 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/20 16:59:08 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Free game at the end of the game or if an error is found
*/

static void			free_game_map(t_game *game)
{
	int y;

	if (game->map.map)
	{
		y = 0;
		while (y < game->map.size_map.y)
			free(game->map.map[y++]);
		free(game->map.map);
	}
	if (game->map.tmp_map)
		free(game->map.tmp_map);
}

static void			free_game_structs(t_game *game)
{
	if (game->textures)
		free(game->textures);
	if (game->sprites)
		free(game->sprites);
}

static void			close_game_window(t_game *game)
{
	if (game->mlx.mlx_loaded)
	{
		if ((mlx_destroy_window(game->mlx.mlx, game->mlx.window)))
			game_error(game, ERROR_MLX_CLOSE_WINDOW, FALSE, FALSE);
	}
}

static void			free_sprites(t_game *game)
{
	int i;

	i = 0;
	if (game->sprites)
	{
		while (i < game->file.n_sprites)
			mlx_destroy_image(game->mlx.mlx, game->sprites[i++].img);
	}
}

void				free_game(t_game *game)
{
	free_game_map(game);
	free_sprites(game);
	free_game_next(game);
	free_game_structs(game);
	close_game_window(game);
	free(game);
}
