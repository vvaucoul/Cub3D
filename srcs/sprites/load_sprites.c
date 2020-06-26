/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:53:23 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/20 20:08:21 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Load sprite in map
**	And all sprite in game
*/

int					found_sprite(char c)
{
	return (c == '2' ? TRUE : FALSE);
}

static void			assign_sprite(t_game *game, int index)
{
	t_vector2d	size;

	size = v_init_vector2d(64, 64);
	if (!(game->sprites[index].img = mlx_xpm_file_to_image(game->mlx.mlx,
	game->file.sprite ? game->file.sprite : DEFAULT_SPRITE, &size.x, &size.y)))
		game_error(game, ERROR_TEXTURE_PATH, TRUE, TRUE);
	if (!(game->sprites[index].data =
	mlx_get_data_addr(game->sprites[index].img,
	&game->sprites[index].bpp, &game->sprites[index].sizel,
	&game->sprites[index].endian)))
		game_error(game, ERROR_MLX_DATA, TRUE, TRUE);
	game->sprites[index].size = (t_vector2d){64, 64};
	game->sprites[index].sprite_char = '2';
}

int					get_n_sprite(t_game *game)
{
	int nsprite;
	int i;
	int j;

	nsprite = 0;
	j = 0;
	while (j < game->map.size_map.y)
	{
		i = 0;
		while (i < game->map.size_map.x)
		{
			if (found_sprite(game->map.map[j][i]))
				++nsprite;
			++i;
		}
		++j;
	}
	return (nsprite);
}

static void			init_loading(int *i1, int *i2, int *i3)
{
	i1[0] = 0;
	i2[0] = 0;
	i3[0] = 0;
}

int					load_sprites(t_game *game)
{
	int actusprite;
	int i;
	int j;

	init_loading(&i, &j, &actusprite);
	if (!(game->sprites = (t_sprites *)malloc(sizeof(t_sprites)
	* get_n_sprite(game) + 1)))
		malloc_error();
	while (j < game->map.size_map.y)
	{
		i = 0;
		while (i < game->map.size_map.x)
		{
			if (found_sprite(game->map.map[j][i]))
			{
				assign_sprite(game, actusprite);
				game->sprites[actusprite].pos = v_init_vector(i, j, 0);
				++actusprite;
			}
			++i;
		}
		++j;
	}
	game->file.n_sprites = actusprite;
	return (0);
}
