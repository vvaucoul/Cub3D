/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:16:11 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 15:58:46 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		check_format(char *str, char *format, int startstr)
{
	int j;

	j = 0;
	while (str[startstr] || format[j])
	{
		if (str[startstr] != format[j])
			return (-1);
		++j;
		++startstr;
	}
	return (1);
}

int		ft_has_format(char *str, char *format)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((check_format(str, format, i)) == 1)
			return (1);
		++i;
	}
	return (0);
}
