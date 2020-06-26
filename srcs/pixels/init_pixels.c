/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:58:43 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 17:26:15 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		init_pixels(t_game *game)
{
	game->pixel.img_ptr = mlx_new_image(game->mlx.mlx,
	game->window.w_res.x, game->window.w_res.y);
	game->pixel.img_data = mlx_get_data_addr(game->pixel.img_ptr,
	&game->pixel.bpp, &game->pixel.size_line, &game->pixel.endian);
	return (0);
}
