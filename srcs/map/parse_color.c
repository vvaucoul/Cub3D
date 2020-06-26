/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:20:37 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/21 16:50:26 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	Parse color from file
*/

t_color			parse_color(char *str)
{
	t_color		color;
	char		*str_trunc;
	int			i;

	i = 0;
	ft_get_next_digit(str, &i);
	str_trunc = ft_strtrunc_to_digit(&i, str);
	color.r = ft_atoi(str_trunc);
	free(str_trunc);
	ft_get_next_digit(str, &i);
	str_trunc = ft_strtrunc_to_digit(&i, str);
	color.g = ft_atoi(str_trunc);
	free(str_trunc);
	ft_get_next_digit(str, &i);
	str_trunc = ft_strtrunc_to_digit(&i, str);
	color.b = ft_atoi(str_trunc);
	free(str_trunc);
	return (color);
}
