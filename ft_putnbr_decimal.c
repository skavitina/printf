/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:49:24 by dalfredi          #+#    #+#             */
/*   Updated: 2022/01/15 19:58:57 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_res(int nb,
			int base, char *radix, int *len)
{
	if (nb == -2147483648)
	{
		print_res(nb / base, base, radix, len);
		*len += ft_putchar_fd(radix[-(nb % base)], 1);
	}
	else if (nb < 0)
	{
		*len += ft_putchar_fd('-', 1);
		print_res(-nb, base, radix, len);
	}
	else
	{
		if (nb < base)
		{
			*len += ft_putchar_fd(radix[nb], 1);
		}
		else
		{
			print_res(nb / base, base, radix, len);
			*len += ft_putchar_fd(radix[nb % base], 1);
		}
	}
}

static int	ft_putnbr_base(int nbr, char *base)
{
	int	int_base;
	int	index;
	int	len;

	index = 0;
	while (base[index] != '\0')
		index++;
	int_base = index;
	len = 0;
	print_res(nbr, int_base, base, &len);
	return (len);
}

int	ft_putnbr_decimal(int nbr)
{
	int		len;

	len = ft_putnbr_base(nbr, "0123456789");
	return (len);
}
