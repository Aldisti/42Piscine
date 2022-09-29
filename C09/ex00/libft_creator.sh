# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 14:47:13 by adi-stef          #+#    #+#              #
#    Updated: 2022/09/29 14:47:18 by adi-stef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
rm -f ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o libfta.a
gcc -Wall -Werror -Wextra -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
