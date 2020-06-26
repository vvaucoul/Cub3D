/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removespaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:52:20 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 22:20:03 by vintz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_removespaces(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new_str = malloc(sizeof(char) * ft_strlen(str) + 2)))
		malloc_error();
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ')
		{
			new_str[j] = str[i];
			++j;
		}
		++i;
	}
	new_str[j] = '\n';
	new_str[j + 1] = '\0';
	return (new_str);
}
