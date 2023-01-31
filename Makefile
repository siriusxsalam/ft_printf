# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:11:29 by hasalam           #+#    #+#              #
#    Updated: 2023/01/30 23:12:03 by hasalam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c\
		ft_putchar.c\
		ft_putluhex.c\
		ft_putnbr.c\
		ft_putpointer.c\
		ft_putstr.c\
		ft_putunsg.c\
		ft_printf_bonus.c

CC = cc
RM = rm -f
CFALGS = -Wall -Wextra -Werror

OBJS = $(SRCS:%.c=%.o)

all: ${NAME}

%.o:%.c ft_printf.h
	${CC} ${CFALGS} -c $<

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

bonus: re

.PHONY: fclean clean re all