/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:49:39 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/21 17:13:38 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Parse str path (texture, sprite and other)
*/

char	*parse_texture(t_game *game, char *str, char *sw)
{
	char	*texture;
	int		i;

	i = 0;
	ft_skip_spaces(str, &i);
	if (!(texture = ft_strtrunc_del(&str[i], '\n')))
		malloc_error();
	if (!(ft_can_be_opened(texture)))
		game_error(game, ft_strjoin(
		ft_strjoin(ERROR_TEXTURE_PATH, " for argument: "), sw), TRUE, TRUE);
	return (texture);
}
