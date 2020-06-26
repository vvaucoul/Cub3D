/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrunc_multi_del.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintz <vintz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 23:10:16 by vintz             #+#    #+#             */
/*   Updated: 2020/02/18 19:27:54 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_up.h"

static int	is_del(char c, char *del)
{
	int i;

	i = 0;
	while (del[i])
	{
		if (del[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char		*ft_strtrunc_multi_del(char *s1, char *del)
{
	char	*str;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && !is_del(s1[i], del))
		++i;
	if (!(str = malloc(sizeof(char) * i + 2)))
		return (NULL);
	i = 0;
	while (s1[i] && !is_del(s1[i], del))
	{
		str[i] = s1[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
