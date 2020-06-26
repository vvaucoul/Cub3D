/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintz <vintz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 00:03:22 by vintz             #+#    #+#             */
/*   Updated: 2020/01/05 14:34:05 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_up.h"

char		*ft_revstr(char *str)
{
	char	*str_r;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	if (!(str_r = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	i = ft_strlen(str) - 1;
	j = 0;
	while (str[j])
	{
		str_r[j] = str[i];
		++j;
		--i;
	}
	str_r[j] = '\0';
	return (str_r);
}
