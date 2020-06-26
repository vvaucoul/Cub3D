/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintz <vintz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 00:15:10 by vintz             #+#    #+#             */
/*   Updated: 2020/01/05 14:34:07 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_up.h"

char		*ft_str_to_lower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isupper(str[i]))
			str[i] += 32;
		++i;
	}
	return (str);
}
