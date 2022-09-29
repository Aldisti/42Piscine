# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 17:06:06 by adi-stef          #+#    #+#              #
#    Updated: 2022/09/29 14:24:12 by adi-stef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
SRC = srcs
SRCS = ${SRC}/ft_putchar.c ${SRC}/ft_swap.c ${SRC}/ft_putstr.c ${SRC}/ft_strlen.c ${SRC}/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
HEADER = includes
CC = gcc ${CFLAGS}
CFLAGS = -Wall -Werror -Wextra
OPTIONS = -I ${HEADER} -c
RM = rm -f

.c.o:
	${CC} ${OPTIONS} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
