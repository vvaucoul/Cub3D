/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:47:38 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/18 20:33:38 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		destroy_image(void *img, char *data)
{
	free(img);
	free(data);
}
