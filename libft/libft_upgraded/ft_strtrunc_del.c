/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrunc_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintz <vintz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 23:10:16 by vintz             #+#    #+#             */
/*   Updated: 2020/02/18 19:27:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_up.h"

char		*ft_strtrunc_del(char *s1, char del)
{
	char	*str;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != del)
		++i;
	if (!(str = malloc(sizeof(char) * i + 2)))
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != del)
	{
		str[i] = s1[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
