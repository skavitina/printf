/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:43:58 by tpeggie           #+#    #+#             */
/*   Updated: 2022/01/24 22:21:38 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		i = ft_putchar('-');
		i += ft_print_num(-n);
	}
	else if (n >= 0 && n <= 9)
		i += ft_putchar (n + '0');
	else if (n >= 10)
	{
		i += ft_print_num (n / 10);
		i += ft_putchar (n % 10 + '0');
	}
	return (i);
}

int	ft_print_unsigned_num(unsigned int n)
{
	int	i;

	i = 0;
	if (n <= 9)
		i += ft_putchar (n + '0');
	else if (n >= 10)
	{
		i += ft_print_unsigned_num (n / 10);
		i += ft_putchar (n % 10 + '0');
	}
	return (i);
}

int	ft_print_hex(unsigned int n, char flag)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_print_hex ((n / 16), flag);
		i += ft_print_hex ((n % 16), flag);
	}
	else
	{
		if (n < 10)
			ft_putchar (n + '0');
		else
		{
			if (flag == 'x')
				ft_putchar (n - 10 + 'a');
			else if (flag == 'X')
				ft_putchar (n - 10 + 'A');
		}
		i++;
	}
	return (i);
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr >= 16)
	{
		i += ft_print_pointer (ptr / 16);
		if (ptr % 16 >= 10)
			i += ft_putchar ((ptr % 16) - 10 + 'a');
		else
			i += ft_putchar ((ptr % 16) + '0');
	}
	else
	{
		if (ptr % 16 >= 10)
			i += ft_putchar ((ptr % 16) - 10 + 'a');
		else
			i += ft_putchar ((ptr % 16) + '0');
	}
	return (i);
}
