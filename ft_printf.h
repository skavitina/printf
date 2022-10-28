/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:44:43 by tpeggie           #+#    #+#             */
/*   Updated: 2022/01/24 22:38:51 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_printf(const char	*format, ...);
int	ft_print_num(int n);
int	ft_print_unsigned_num(unsigned int n);
int	ft_print_hex(unsigned int n, char flag);
int	ft_print_pointer(unsigned long long ptr);

#endif
