/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrunc_limits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintz <vintz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 23:22:01 by vintz             #+#    #+#             */
/*   Updated: 2020/01/05 14:34:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_up.h"

char		*ft_strtrunc_limits(char *s1, int min, int max)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	if (min > (int)ft_strlen(s1) || max > (int)ft_strlen(s1)
	|| min < 0 || max < 0 || max < min)
		return (NULL);
	i = min;
	while (s1[i] && i <= max)
		++i;
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = min;
	j = 0;
	while (s1[i] && i <= max)
	{
		str[j] = s1[i];
		++i;
		++j;
	}
	str[j] = '\0';
	return (str);
}
