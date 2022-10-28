/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 19:31:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/10/28 15:57:53 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Parse game resolution
*/

static void		check_res(t_vector2d *res, t_bool x)
{
	if (x)
	{
		if (res[0].x > MAX_SCREEN_RES_X)
			game_warning(WARNING_RES_X_HIGH);
		else if (res[0].x < MIN_SCREEN_RES_X)
			game_warning(WARNING_RES_X_SMALL);
		res[0].x = res[0].x >
		MAX_SCREEN_RES_X ? MAX_SCREEN_RES_X : res[0].x;
		res[0].x = res[0].x <
		MIN_SCREEN_RES_X ? DEFAULT_SCREEN_RES_X : res[0].x;
	}
	else
	{
		if (res[0].y > MAX_SCREEN_RES_Y)
			game_warning(WARNING_RES_Y_HIGH);
		else if (res[0].y < MIN_SCREEN_RES_Y)
			game_warning(WARNING_RES_Y_SMALL);
		res[0].y = res[0].y >
		MAX_SCREEN_RES_Y ? MAX_SCREEN_RES_Y : res[0].y;
		res[0].y = res[0].y <
		MIN_SCREEN_RES_Y ? DEFAULT_SCREEN_RES_Y : res[0].y;
	}
}

t_vector2d		parse_res(char *str)
{
	t_vector2d	res;
	char		*a_res;
	char		*tmp;
	int			i;

	i = 0;
	a_res = malloc(sizeof(char) * RES_MAX_LEN);
	ft_skip_spaces(str, &i);
	tmp = ft_strtrunc_del(&str[i], ' ');
	res.x = ft_atoi(tmp);
	check_res(&res, TRUE);
	free(tmp);
	free(a_res);
	a_res = malloc(sizeof(char) * RES_MAX_LEN);
	ft_skip_spaces(str, &i);
	tmp = ft_strtrunc_del(&str[i], ' ');
	res.y = ft_atoi(tmp);
	check_res(&res, FALSE);
	free(tmp);
	free(a_res);
	return (res);
}
