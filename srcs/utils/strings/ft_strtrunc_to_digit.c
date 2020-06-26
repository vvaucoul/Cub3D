/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrunc_to_digit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:40:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/21 16:50:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "functions.h"

char	*ft_strtrunc_to_digit(int *i, char *str)
{
	char	*newstr;
	int		j;

	j = 0;
	if (!(newstr = malloc(sizeof(char) * (ft_strlen(str) - i[0]) + 1)))
		return (NULL);
	while (str[i[0]] && ft_isdigit(str[i[0]]))
	{
		newstr[j] = str[i[0]];
		++i[0];
		++j;
	}
	newstr[j] = 0;
	return (newstr);
}
