/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:49:24 by dalfredi          #+#    #+#             */
/*   Updated: 2022/01/13 23:16:58 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_res(unsigned int nb, unsigned int base, char *radix, int *len)
{
	if (nb < base)
	{
		(*len)++;
		ft_putchar_fd(radix[nb], 1);
	}
	else
	{
		print_res(nb / base, base, radix, len);
		(*len)++;
		ft_putchar_fd(radix[nb % base], 1);
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

int	ft_putnbr_hexadecimal(int nbr, char hex_case)
{
	int		len;

	if (hex_case == 'x')
		len = ft_putnbr_base(nbr, "0123456789abcdef");
	else
		len = ft_putnbr_base(nbr, "0123456789ABCDEF");
	return (len);
}
