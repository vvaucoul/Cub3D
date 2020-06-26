/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintz <vintz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:34:12 by vintz             #+#    #+#             */
/*   Updated: 2020/01/05 14:34:03 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_up.h"

char		*ft_realloc(char *ptr, size_t size)
{
	char	*new_ptr;
	int		i;

	if (!ptr)
	{
		if (!(new_ptr = malloc(sizeof(char) * size + 1)))
			return (NULL);
		else
			return (new_ptr);
	}
	else
	{
		i = 0;
		if (!(new_ptr = malloc(sizeof(char) * ft_strlen(ptr) + size + 1)))
			return (NULL);
		while (ptr[i])
		{
			new_ptr[i] = ptr[i];
			++i;
		}
		new_ptr[i] = '\0';
	}
	return (new_ptr);
}
