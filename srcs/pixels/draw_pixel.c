/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:11:20 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 17:25:58 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		draw_pixel(t_game *game, t_vector2d coord, int color)
{
	if (coord.x < game->window.w_res.x && coord.y <
	game->window.w_res.y && coord.x > 0 && coord.y > 0)
		ft_memcpy(game->pixel.img_data + 4
		* game->window.w_res.x * coord.y + coord.x * 4,
		&color, sizeof(int));
	return (0);
}
