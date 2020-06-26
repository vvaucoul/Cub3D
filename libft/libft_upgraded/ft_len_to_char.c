/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_to_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintz <vintz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 23:35:50 by vintz             #+#    #+#             */
/*   Updated: 2020/01/05 14:34:00 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_up.h"

int		ft_len_to_char(char *str, char c)
{
	int len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != c)
		++len;
	return (len);
}
