# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpeggie <tpeggie@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 11:45:04 by tpeggie           #+#    #+#              #
#    Updated: 2022/01/24 11:45:12 by tpeggie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_printf.c \
		ft_printf_utils.c\

OBJ = ${SRC:.c=.o}
INCS = ft_printf.h
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
RM = rm -f

%.o :	%.c ${INCS}
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}:	${OBJ}
	${LIB} ${NAME} ${OBJ}

all:	${NAME}

clean:
	$(RM) ${OBJ}

fclean:	clean
	$(RM) ${NAME}

re:	fclean all

norme:
	norminette ${SRC} ${INCS}

.PHONY:		all clean fclean re
