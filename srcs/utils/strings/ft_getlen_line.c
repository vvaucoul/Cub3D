/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlen_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:28:15 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/16 15:58:09 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		get_len_line(char *str, int i)
{
	int start;

	start = i;
	while (!is_eol(str[i]))
		++i;
	return ((i - start) + 1);
}
