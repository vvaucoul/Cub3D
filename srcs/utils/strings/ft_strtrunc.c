/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:51:04 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/17 20:32:28 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
** Fonction permettant de tronquer la chaine
** et renvoyer jusqu au caractere defini
*/

char	*ft_strtrunc(char *str, char c)
{
	char	*sr;
	int		i;

	i = 0;
	while (str[i] != c && str[i])
		++i;
	if (!(sr = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
	{
		sr[i] = str[i];
		++i;
	}
	sr[i] = '\0';
	return (sr);
}
