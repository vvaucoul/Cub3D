/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:41:31 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 13:38:35 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				exit_screenshot(t_game *game)
{
	write(1, "Screenshot saved\n", ft_strlen("Screenshot saved\n"));
	quit_game(game);
}

void				set_bmp_value(unsigned char *bmp_header, int value)
{
	bmp_header[0] = (unsigned char)(value);
	bmp_header[1] = (unsigned char)(value >> 8);
	bmp_header[2] = (unsigned char)(value >> 16);
	bmp_header[3] = (unsigned char)(value >> 24);
}

unsigned char		set_uchar(int c)
{
	return ((unsigned char)c);
}
