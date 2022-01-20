SRC = ft_printf.c \
	ft_putnbr_pointer.c \
	ft_putnbr_decimal.c \
	ft_putnbr_unsigned.c \
	ft_putnbr_hexadecimal.c

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
