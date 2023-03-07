# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 12:49:39 by rthomas           #+#    #+#              #
#    Updated: 2022/04/19 13:23:02 by rthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES =	ft_printf.c \
			ft_itoa_print.c \
			ft_itoa_uprint.c \
			ft_itoa_print_hex.c \
			ft_print_p.c \
		 	ft_utils.c

OBJECTS = ${SOURCES:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJECTS}
	ar rc ${NAME} ${OBJECTS}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re