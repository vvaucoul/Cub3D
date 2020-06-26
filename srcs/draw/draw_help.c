/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:48:21 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/13 15:02:36 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Fnction to draw help text
*/

int		draw_help(t_game *game)
{
	draw_text(game, (t_vector2d){game->window.w_res.x - (32 * 10), 32},
	color(255, 255, 255), "Help :");
	draw_text(game, (t_vector2d){game->window.w_res.x - (32 * 10), 32 * 2},
	color(255, 255, 255), "WASD to move");
	draw_text(game, (t_vector2d){game->window.w_res.x - (32 * 10), 32 * 2.5},
	color(255, 255, 255), "H to toggle display this help");
	draw_text(game, (t_vector2d){game->window.w_res.x - (32 * 10), 32 * 3},
	color(255, 255, 255), "T to toggle display textures");
	draw_text(game, (t_vector2d){game->window.w_res.x - (32 * 10), 32 * 3.5},
	color(255, 255, 255), "L SHIFT TO RUN");
	return (0);
}
