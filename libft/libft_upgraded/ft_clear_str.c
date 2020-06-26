/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintz <vintz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 23:40:31 by vintz             #+#    #+#             */
/*   Updated: 2020/01/05 14:33:49 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_up.h"

/*
** Fonctions permettant d'enlever les caractères obstruants la chaine
** (' ', '\n', '\t') etc...
*/

int		get_last_space(char *str, int *i)
{
	while (ft_is_whitespace(str[i[0]]) && str[i[0]])
		++i[0];
	return (0);
}

int		add_space(char **str, int *j, int *i)
{
	str[0][j[0]] = ' ';
	++j[0];
	++i[0];
	return (0);
}

char	*ft_clear_str(char *str)
{
	char	*str_c;
	int		i;
	int		j;

	if (!(str_c = malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			add_space(&str_c, &j, &i);
		if (ft_is_whitespace(str[i]))
			get_last_space(str, &i);
		str_c[j] = str[i];
		++i;
		++j;
	}
	str_c[j] = '\0';
	return (str_c);
}
