
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

int	converse_arg(char flag, va_list arg)// в va_arg указываем какой тип аргументов мы хотим получить
{
	int	length;

	length = 0;
	if (flag == 'c')// печать 1 символа
		length += ft_putchar_fd(va_arg(arg, int), 1);//указатель на список аргументов и тип переменной который хотим получить 
	else if (flag == 's')//печать строки
		length += ft_putstr_fd(va_arg(arg, char *), 1);// указатель на список аргументов и тип переменной который хотим получить 
	else if (flag == 'p')//Аргумент указателя *void должен быть напечатан в шестнадцатиричном формате
		length += ft_putstr_fd("0x", 1) + ft_putnbr_pointer(
				va_arg(arg, unsigned long int));//литерал для указателя. unsigned long потому что указатель это 4 байт - вырабатывается в соответствии с 4х байтовой системой 
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

int	ft_printf(const char *format, ...)// функция с переменным количеством переменных. Для определения параметров неопределенной длины в таких функциях используется многоточие
{
	va_list	argptr; // тип va_list опеределен в файле stdarg.h. . Позволяет обрабатывать списки параметров с нефиксированным количеством
	int		length;// количество символов, которые печатать буду

	va_start(argptr, format);// Получаем указатель на начало списка аргументов, format - последний аргумент известного размера
	length = 0;
	while (*format)//посимвольно иду по аргументам
	{
		if (*format != '%')// если аргумент не равен знаку процента ,значит посимвольно выводим аргументы 
			length += ft_putchar_fd(*format, 1); // посимвольная печать значений format
		else
		{	
			format++;// если все-таки встречаем знак процента -> то пропускаем его и смотрим на следующий символ
			if (*format == '%') // если 2% подряд то выводим процент
				length += ft_putchar_fd(*format, 1);//подсчет количества аргументов посимвольно
			else
				length += converse_arg(*format, argptr);// если что-то другое,то переходим в функцию converse arg - то есть преобразование аргумента
		}
		format++;
	}
	va_end(argptr);
	return (length);
}