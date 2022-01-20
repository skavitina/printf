
#include "ft_printf.h"

void	ft_putnbr_fd(unsigned int nbr, int *count)
{
	if (nbr <= 9)
	{
		(*count)++;
		ft_putchar_fd(48 + nbr, 1);
	}
	else
	{
		ft_putnbr_fd(nbr / 10, count);
		(*count)++;
		ft_putchar_fd(48 + nbr % 10, 1);
	}
}

int	ft_putnbr_unsigned(unsigned int nbr)
{	
	int	len;

	len = 0;
	ft_putnbr_fd(nbr, &len);
	return (len);
}