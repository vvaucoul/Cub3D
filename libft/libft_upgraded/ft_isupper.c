/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintz <vintz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 00:16:35 by vintz             #+#    #+#             */
/*   Updated: 2020/01/05 14:33:55 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_up.h"

int		ft_isupper(char c)
{
	return (c >= 65 && c <= 90 ? 1 : 0);
}
