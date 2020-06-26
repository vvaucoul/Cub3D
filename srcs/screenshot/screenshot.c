/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 13:38:20 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/20 16:46:12 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static	int		header_bitmap(int fd, int filesize, t_game *game)
{
	int				ret;
	unsigned char	bmp_header[SCREEN_HEADER_SIZE];

	ft_bzero(bmp_header, 54);
	bmp_header[0] = set_uchar('B');
	bmp_header[1] = set_uchar('M');
	set_bmp_value(bmp_header + 2, filesize);
	bmp_header[10] = set_uchar(54);
	bmp_header[14] = set_uchar(40);
	set_bmp_value(bmp_header + 18, game->window.w_res.x);
	set_bmp_value(bmp_header + 22, game->window.w_res.y);
	bmp_header[27] = set_uchar(1);
	bmp_header[28] = set_uchar(24);
	ret = write(fd, bmp_header, SCREEN_HEADER_SIZE);
	return (ret);
}

static int		get_color_from_coords(t_game *game, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int*)(game->pixel.img_data
			+ (4 * game->window.w_res.x * (game->window.w_res.y - 1 - y))
			+ (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int		data_bitmap(int fd, int extrabytes, t_game *game)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					y;
	int					x;
	int					color;

	y = 0;
	while (y < game->window.w_res.y)
	{
		x = 0;
		while (x < game->window.w_res.x)
		{
			color = get_color_from_coords(game, x, y);
			if (write(fd, &color, 3) < 0)
				return (0);
			if (extrabytes > 0 && write(fd, &zero, extrabytes) < 0)
				return (0);
			++x;
		}
		++y;
	}
	return (1);
}

int				screenshot(t_game *game)
{
	int		fd;
	int		extrabytes;
	int		filesize;

	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND))
	< 0)
		game_error(game, ERROR_SCREEENSHOT_CREATE, FALSE, TRUE);
	extrabytes = (4 - (game->window.w_res.x * 3) % 4) % 4;
	filesize = SCREEN_HEADER_SIZE
	+ (game->window.w_res.x * 3 + extrabytes) * game->window.w_res.y;
	if (!(header_bitmap(fd, filesize, game)))
		game_error(game, ERROR_SCREEENSHOT_WRITE, FALSE, TRUE);
	if (!(data_bitmap(fd, extrabytes, game)))
		game_error(game, ERROR_SCREEENSHOT_WRITE, FALSE, TRUE);
	close(fd);
	exit_screenshot(game);
	return (1);
}
