# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 04:55:23 by himejjad          #+#    #+#              #
#    Updated: 2022/11/17 01:21:36 by himejjad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_hexdec.c \
		ft_unsputnbr.c \

OBJS = ${SRCS:.c=.o}


all: $(NAME)

$(NAME): ${OBJS} 
		ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
