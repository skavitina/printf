/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:44:31 by tpeggie           #+#    #+#             */
/*   Updated: 2022/01/24 22:32:41 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

static int	converse_arg(char flag, va_list args)
{
	if (flag == 'c')
		return (ft_putchar (va_arg(args, int)));
	if (flag == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (flag == 'p')
	{
		ft_putstr("0x");
		return (ft_print_pointer(va_arg(args, unsigned long long)) + 2);
	}
	if (flag == '%')
		return (ft_putchar(flag));
	if (flag == 'd' || flag == 'i')
		return (ft_print_num(va_arg(args, int)));
	if (flag == 'u')
		return (ft_print_unsigned_num(va_arg(args, unsigned int)));
	if (flag == 'x')
		return (ft_print_hex(va_arg(args, int), flag));
	if (flag == 'X')
		return (ft_print_hex(va_arg(args, int), flag));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		argptr;
	int			sym_printed;
	int			i;

	va_start(argptr, format);
	if (!format)
		return (0);
	i = 0;
	sym_printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			sym_printed += converse_arg(format[i + 1], argptr);
			i++;
			if (!format[i + 1])
				break ;
		}
		else
			sym_printed += ft_putchar(format[i]);
		i++;
	}
	va_end(argptr);
	return (sym_printed);
}
