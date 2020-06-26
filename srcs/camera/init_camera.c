/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 18:43:55 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/20 20:11:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
** Init camera location, angle by character {N,S,W,E}
** Check also if only 1 cam character is in the map
*/

static t_bool				is_cam_char(char c)
{
	int i;

	i = 0;
	while (ALL_CAM_CHAR[i])
	{
		if (ALL_CAM_CHAR[i] == c)
			return (TRUE);
		++i;
	}
	return (FALSE);
}

static int					check_file_has_one_cam(t_game *game)
{
	t_vector2d	position;
	int			i;

	i = 0;
	position = v_init_vector2d(0, 0);
	while (position.y < game->map.size_map.y)
	{
		while (position.x < game->map.size_map.x)
		{
			if (is_cam_char(game->map.map[position.y][position.x]))
			{
				++i;
				if (i > 1)
					return (-1);
			}
			++position.x;
		}
		position.x = 0;
		++position.y;
	}
	if (i <= 0)
		return (-2);
	return (TRUE);
}

static t_vector				get_camera_position(t_game *game)
{
	t_vector2d position;

	position = v_init_vector2d(0, 0);
	while (position.y < game->map.size_map.y)
	{
		while (position.x < game->map.size_map.x)
		{
			if ((game->cam.dir = (ft_isdirection_map(game->map.map[position.y]
				[position.x]))))
			{
				game->map.map[position.y][position.x] = '0';
				return ((t_vector){position.x, position.y, 0});
			}
			++position.x;
		}
		position.x = 0;
		++position.y;
	}
	return ((t_vector){position.x, position.y, 0});
}

int							init_camera(t_game *game)
{
	int	cam_error;

	if ((cam_error = check_file_has_one_cam(game)) < 0)
	{
		if (cam_error == -1)
			game_error(game, ERROR_DOUBLON_CAM, TRUE, TRUE);
		else if (cam_error == -2)
			game_error(game, ERROR_NO_CAM, TRUE, TRUE);
	}
	game->cam.fov = FOV;
	game->cam.pos = get_camera_position(game);
	game->cam.projection_center.x = game->window.w_res.x / 2;
	game->cam.projection_center.y = game->window.w_res.y / 2;
	if (game->cam.dir == 1)
		game->cam.angle = 90;
	if (game->cam.dir == 2)
		game->cam.angle = 270;
	if (game->cam.dir == 3)
		game->cam.angle = 0;
	if (game->cam.dir == 4)
		game->cam.angle = 180;
	return (0);
}
