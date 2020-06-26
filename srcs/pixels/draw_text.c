/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:56:17 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 12:47:10 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		draw_text(t_game *game, t_vector2d pos, int color, char *str)
{
	mlx_string_put(game->mlx.mlx, game->mlx.window, pos.x, pos.y, color, str);
	return (0);
}
