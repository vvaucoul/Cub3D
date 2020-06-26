/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 14:53:56 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 15:49:52 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int			color_to_int(t_color vcolor)
{
	return (color(vcolor.r, vcolor.g, vcolor.b));
}

t_color		subtract_color(t_color color, int sub)
{
	color.r /= sub;
	color.g /= sub;
	color.b /= sub;
	return (color);
}

int			shade_color(int color, float divide)
{
	if (divide <= 1.0)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
		+ ((int)((0x0000FF & color) / divide)));
}

int			deg_color(int r, int g, int b, float distance)
{
	int rgb;

	rgb = r * distance;
	rgb = (rgb << 8) + (g * distance);
	rgb = (rgb << 8) + (b * distance);
	return (rgb);
}

int			color(int red, int green, int blue)
{
	int rgb;

	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}
