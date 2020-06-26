/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintz <vintz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 01:05:54 by vintz             #+#    #+#             */
/*   Updated: 2020/01/05 14:34:09 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_up.h"

int		malloc_tab(char *str, char del)
{
	int max;
	int i;

	i = 0;
	max = 0;
	while (str[i])
	{
		if (str[i] == del)
		{
			if (i > max)
				max = i + 1;
			max = 0;
		}
		++max;
		++i;
	}
	return (max);
}

char	**init_tab(char *str, char del)
{
	char	**tab;
	int		i;
	int		y;
	int		actu;

	if (!(tab = (char **)malloc(sizeof(char *) * ((ft_nchar_in_str(str, del)) *
		malloc_tab(str, del)) + 1)))
		return (NULL);
	i = 0;
	actu = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == del)
		{
			if (!(tab[y] = (char *)malloc(sizeof(char) * (i - actu) + 1)))
				return (NULL);
			actu = i;
			++y;
		}
		++i;
	}
	if (!(tab[y] = (char *)malloc(sizeof(char) * (i - actu) + 1)))
		return (NULL);
	return (tab);
}

void	init_values(int *i, int *x, int *y)
{
	i[0] = 0;
	x[0] = 0;
	y[0] = 0;
}

char	**ft_str_to_tab(char *str, char del)
{
	char	**tab;
	int		i;
	int		x;
	int		y;

	if (!(tab = init_tab(str, del)))
		return (NULL);
	init_values(&i, &x, &y);
	while (str[i])
	{
		if (str[i] == del)
		{
			tab[y][x] = '\0';
			++y;
			x = 0;
			++i;
		}
		tab[y][x] = str[i];
		++i;
		++x;
	}
	tab[y][x] = '\0';
	tab[y + 1] = NULL;
	return (tab);
}
