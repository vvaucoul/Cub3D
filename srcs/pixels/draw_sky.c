/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:49:28 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 17:26:06 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
** Draw sky
*/

void		draw_sky(t_game *game)
{
	if (game->a_ray.draw_start > 0
	&& game->a_ray.x < (game->window.w_res.x) && 0 < (game->window.w_res.y))
		draw_vertical_line(game, game->a_ray.x, (t_vector2d){-1,
		game->a_ray.draw_start + 1}, game->file.top_color);
}
