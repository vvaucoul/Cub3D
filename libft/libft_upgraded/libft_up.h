/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_up.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:35:59 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/19 18:16:35 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UP_H
# define LIBFT_UP_H

# include "../libft.h"

# include <unistd.h>
# include <stdlib.h>

/*
**                         __                  _   _
**                        / _|                | | (_)
**      _ __ ___  _   _  | |_ _   _ _ __   ___| |_ _  ___  _ __  ___
**     | '_ ` _ \| | | | |  _| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
**     | | | | | | |_| | | | | |_| | | | | (__| |_| | (_) | | | \__ \
**     |_| |_| |_|\__, | |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
**                 __/ |
**                |___/
*/

char			*ft_realloc(char *ptr, size_t size);
char			*ft_strtrunc_del(char *s1, char del);
char			*ft_strtrunc_limits(char *s1, int min, int max);
int				ft_len_to_char(char *str, char c);
char			*ft_clear_str(char *str);
int				ft_is_whitespace(char c);
char			*ft_revstr(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_isupper(char c);
int				ft_islower(char c);
char			*ft_str_to_lower(char *str);
char			*ft_str_to_upper(char *str);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strcat(char *dest, char *src);
int				ft_abs(int n);
char			**ft_str_to_tab(char *str, char del);
int				ft_nchar_in_str(char *str, char c);
char			*ft_strtrunc_multi_del(char *s1, char *del);

/*
** convert bases
*/

char			*ft_itoa_base(int nb, int base);
char			*ft_itoa_neg_base(int nb, int base);

/*
** display
*/

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_showtab(char **tab);

#endif
