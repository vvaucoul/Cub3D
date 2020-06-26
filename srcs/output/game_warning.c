/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_warning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:53:12 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/21 14:59:04 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			game_warning(char *str)
{
	write(1, "\t - WARNING : ", ft_strlen("\t - WARNING : "));
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
