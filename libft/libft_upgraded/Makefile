# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 15:43:31 by vvaucoul          #+#    #+#              #
#    Updated: 2020/02/19 18:32:46 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_upgraded.a

SRCSM =		./ft_abs.c \
			./ft_isupper.c \
			./ft_islower.c \
			./ft_is_whitespace.c \
			./ft_len_to_char.c \
			./ft_nchar_in_str.c \
			./ft_clear_str.c \
			./ft_itoa_base.c \
			./ft_putchar.c \
			./ft_itoa_neg_base.c \
			./ft_revstr.c \
			./ft_realloc.c \
			./ft_putstr.c \
			./ft_str_to_lower.c \
			./ft_str_to_upper.c \
			./ft_strcat.c \
			./ft_strcpy.c \
			./ft_showtab.c \
			./ft_strtrunc_limits.c \
			./ft_strcmp.c \
			./ft_strtrunc_multi_del.c \
			./ft_str_to_tab.c \
			./ft_strtrunc_del.c \


CC = gcc

AR = ar -rc

FLAGS = 		-Wall -Wextra -Werror

OBJ =         $(SRCS:.c=.o)

OBJB =         $(SRCSB:.c=.o)

OBJM =         $(SRCSM:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -I. -c $< -o ${<:.c=.o}

all:         $(NAME)

$(NAME):     $(OBJ) $(OBJM)
	$(AR) $(NAME) $(OBJ) $(OBJM)

clean:
	rm -f $(OBJ) $(OBJB) $(OBJM)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:     all clean re fclean
