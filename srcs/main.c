/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:14:37 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/21 17:17:01 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Start cub3D
*/

static void			init_mlx(t_game *game)
{
	if (!(game->mlx.mlx = mlx_init()))
		game_error(game, ERROR_MLX_MLX, FALSE, FALSE);
	if (!(game->mlx.window = mlx_new_window(game->mlx.mlx,
	game->window.w_res.x, game->window.w_res.y,
	game->window.window_name)))
		game_error(game, ERROR_MLX_WINDOW, FALSE, FALSE);
	game->mlx.mlx_loaded = TRUE;
}

int					main(int argc, char **argv)
{
	t_game	*game;

	if (!(game = (t_game *)malloc(sizeof(t_game))))
		malloc_error();
	init_game_values(game);
	check_args(game, argc, argv);
	parse_file(game, argv[1]);
	init_camera(game);
	init_mlx(game);
	load_textures(game);
	load_sprites(game);
	draw_screen(game);
	if (game->file.screenshot)
		screenshot(game);
	mlx_hook(game->mlx.window, 17, 0, quit_game, game);
	mlx_hook(game->mlx.window, 2, 0, key_pressed, game);
	mlx_hook(game->mlx.window, 3, 1, key_released, game);
	mlx_loop_hook(game->mlx.mlx, checkinputs, game);
	mlx_loop(game->mlx.mlx);
	return (0);
}
