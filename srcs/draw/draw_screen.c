/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:55:38 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/21 16:37:44 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Main function to dispay pixels in screen
**	Steps are : - Init pixel image
**				- Check events
**				- raycasting [display walls - sky - floor]
**				- Minimap
**				- User Interface
**				- Display them on the screen
**				- Destroy image to reload another one
*/

void		draw_screen(t_game *game)
{
	init_pixels(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
		game->pixel.img_ptr, 0, 0);
	if (game->input.draw_help)
		draw_help(game);
	mlx_destroy_image(game->mlx.mlx, game->pixel.img_ptr);
}
