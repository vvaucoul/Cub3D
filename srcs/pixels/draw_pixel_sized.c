/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_sized.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:33:55 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 12:49:37 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		draw_pixel_sized(t_game *game, t_vector2d coord, int size, int color)
{
	t_vector2d actu_coord;

	actu_coord = v_init_vector2d(coord.x, coord.y);
	while (actu_coord.y < coord.y + size)
	{
		while (actu_coord.x < coord.x + size)
		{
			draw_pixel(game, actu_coord, color);
			++actu_coord.x;
		}
		actu_coord.x = coord.x;
		++actu_coord.y;
	}
	return (0);
}
