/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:22:54 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/21 17:07:40 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	load file then,
** 	parse each element in map .cub
*/

static t_bool	load_file(t_game *game, char *pathfile)
{
	if ((game->file.fd = open(pathfile, O_RDONLY)) < 0)
		return (FALSE);
	return (TRUE);
}

static t_bool	switch_parse(t_game *game, char *line, char *sw)
{
	if (!(is_valid_key(game, sw)))
		return (FALSE);
	else
		add_key_to_dic(game, sw);
	if ((ft_strcmp(sw, "R")) == 0)
		game->window.w_res = parse_res(line);
	else if ((ft_isdirection(sw)) == 1)
		apply_texture(game, parse_texture(game, line, sw), sw);
	else if ((ft_strcmp(sw, "S")) == 0)
		game->file.sprite = parse_texture(game, line, sw);
	else if ((ft_strcmp(sw, "F")) == 0)
		game->file.floor_color = color_to_int(parse_color(line));
	else if ((ft_strcmp(sw, "C")) == 0)
		game->file.top_color = color_to_int(parse_color(line));
	else if (ft_isdigit(sw[0]))
		parse_map(game, line);
	free(sw);
	return (TRUE);
}

int				parse_file(t_game *game, char *pathfile)
{
	char	*line;
	int		i;

	if (!(load_file(game, pathfile)))
		game_error(game, ERROR_INVALID_MAP, FALSE, TRUE);
	i = 0;
	while ((get_next_line(game->file.fd, &line)) > 0)
	{
		if (line[0])
		{
			if (switch_parse(game, line, ft_strtrunc_del(line, ' ')) != TRUE)
				game_error(game, ERROR_INVALID_CONFIGURATION, TRUE, TRUE);
		}
		free(line);
	}
	free(line);
	assign_map(game);
	return (0);
}
