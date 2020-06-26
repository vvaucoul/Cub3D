/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:48:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 17:25:47 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
** Draw floor
*/

void		draw_floor(t_game *game)
{
	int y;
	int color;

	if (game->a_ray.draw_end > 0)
	{
		y = game->a_ray.draw_end - 1;
		if (game->a_ray.x < (game->window.w_res.x)
		&& y < (game->window.w_res.y))
		{
			while (y < game->window.w_res.y)
			{
				color = shade_color(game->file.floor_color, 1);
				ft_memcpy(game->pixel.img_data + 4 *
				(game->window.w_res.x) * y + game->a_ray.x * 4,
				&color, sizeof(int));
				++y;
			}
		}
	}
}
