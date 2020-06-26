/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintz <vintz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 00:09:09 by vintz             #+#    #+#             */
/*   Updated: 2020/01/31 12:50:53 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_up.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int j;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	while (s2[j])
		++j;
	if (i > j)
		return (1);
	else if (i < j)
		return (-1);
	return (0);
}
