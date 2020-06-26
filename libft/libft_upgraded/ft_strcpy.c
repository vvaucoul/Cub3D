/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintz <vintz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 00:23:22 by vintz             #+#    #+#             */
/*   Updated: 2020/01/05 14:34:16 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_up.h"

char		*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	if (!src)
		return (NULL);
	if (!dest)
	{
		if (!(dest = malloc(sizeof(char) * ft_strlen(src) + 1)))
			return (NULL);
	}
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
