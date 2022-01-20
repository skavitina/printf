
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

size_t	ft_strlen(const char *s);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_pointer(unsigned long int nbr);
int		ft_putnbr_decimal(int nbr);
int		ft_putnbr_unsigned(unsigned int nbr);
int		ft_putnbr_hexadecimal(int nbr, char hex_case);

#endif