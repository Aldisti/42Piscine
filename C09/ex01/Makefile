# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 17:06:06 by adi-stef          #+#    #+#              #
#    Updated: 2022/09/27 18:54:48 by adi-stef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
$NAME= libft.a
$CC = gcc
$FLAG = -Wall -Wextra -Werror
$SRCS= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
$OBJS= srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o srcs/ft_swap.o
$INCS= includes/
$LIB= ar rc

ALL:
	$(CC $(FLAG)) -o  $(NAME)

CLEAN:
	rm -f $(OBJS)

FCLEAN: CLEAN
	rm -f $(NAME)

RE: FCLEAN all
