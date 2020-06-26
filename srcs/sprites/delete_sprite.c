/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 03:52:44 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 13:39:02 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		delete_sprite(t_game *game, int spriteremove)
{
	t_sprites	tmp;
	int			i;

	i = spriteremove;
	while (i < game->file.n_sprites)
	{
		tmp = game->sprites[i];
		game->sprites[i] = game->sprites[i + 1];
		game->sprites[i + 1] = tmp;
		++i;
	}
	--game->file.n_sprites;
}
