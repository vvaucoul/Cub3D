/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:27:31 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/15 11:27:37 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_strmove(char *s1)
{
	char *tmp;
	char *base;

	base = s1;
	tmp = s1;
	while (*tmp)
		tmp++;
	tmp++;
	while (*tmp)
		*s1++ = *tmp++;
	*s1 = *tmp;
	s1 = base;
}
