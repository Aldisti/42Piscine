# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 17:21:54 by adi-stef          #+#    #+#              #
#    Updated: 2022/09/29 18:03:02 by adi-stef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = do-op
SRCS = ft_do_op.c ft_atoi.c ft_putnbr.c ft_operators.c
OBJS = ${SRCS:.c=.o}
CC = gcc ${CFLAGS}
CFLAGS = -Wall -Werror -Wextra
OPTIONS = -c
RM = rm -f

.c.o:
	${CC} ${OPTIONS} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${CC} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
