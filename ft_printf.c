/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:05:09 by dalfredi          #+#    #+#             */
/*   Updated: 2022/01/15 19:58:12 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}

int	converse_arg(char flag, va_list arg)
{
	int	length;

	length = 0;
	if (flag == 'c')
		length += ft_putchar_fd(va_arg(arg, int), 1);
	else if (flag == 's')
		length += ft_putstr_fd(va_arg(arg, char *), 1);
	else if (flag == 'p')
		length += ft_putstr_fd("0x", 1) + ft_putnbr_pointer(
				va_arg(arg, unsigned long int));
	else if (flag == 'd')
		length += ft_putnbr_decimal(va_arg(arg, int));
	else if (flag == 'i')
		length += ft_putnbr_decimal(va_arg(arg, int));
	else if (flag == 'u')
		length += ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (flag == 'x')
		length += ft_putnbr_hexadecimal(va_arg(arg, int), flag);
	else if (flag == 'X')
		length += ft_putnbr_hexadecimal(va_arg(arg, int), flag);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		length;

	va_start(argptr, format);
	length = 0;
	while (*format)
	{
		if (*format != '%')
			length += ft_putchar_fd(*format, 1);
		else
		{	
			format++;
			if (*format == '%')
				length += ft_putchar_fd(*format, 1);
			else
				length += converse_arg(*format, argptr);
		}
		format++;
	}
	va_end(argptr);
	return (length);
}
