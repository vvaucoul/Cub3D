/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:44:42 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 15:52:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char		*ft_get_texture_path(char *line)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * get_len_line(line, 0) + 1);
	i = 0;
	j = 0;
	while (line[j] != ' ')
		++j;
	while (line[j] == ' ')
		++j;
	while (line[i])
	{
		str[i] = line[j];
		++i;
	}
	str[i] = '\0';
	return (str);
}
