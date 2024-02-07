#include "ft_printf.h"

static int	ft_putp(unsigned long int n, int size, int first)
{
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (first)
	{
		size += write(1, "0x", 2);
		first = 0;
	}
	if (n / 16 > 0)
		size += ft_putp(n / 16, 1, first);
	if (n % 16 > 9)
		ft_putchar(n % 16 + 'a' - 10);
	else
		ft_putchar(n % 16 + '0');
	return (size);
}

static int	convert(char sign, va_list args)
{
	int		count;

	if (sign == 'c')
		count = ft_putchar(va_arg(args, int));
	if (sign == 's')
		count = ft_putstr((va_arg(args, char *)));
	if (sign == 'p')
		count = ft_putp(((unsigned long int)va_arg(args, void *)), 1, 1);
	if (sign == 'd' || sign == 'i')
		count = ft_putnbr((va_arg(args, int)), 1);
	if (sign == 'u')
		count = ft_putunsigned((va_arg(args, unsigned int)), 1);
	if (sign == 'x')
		count = ft_hexa((va_arg(args, int)), 1, 0);
	if (sign == 'X')
		count = ft_hexa((va_arg(args, int)), 1, 1);
	if (sign == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			pos;
	int			ret;

	va_start (args, format);
	ret = 0;
	if (!format)
		return (-1);
	pos = 0;
	while (format[pos])
	{
		if (format[pos] == '%')
			ret += convert((format[++pos]), args);
		else
			ret += write(1, &format[pos], 1);
		pos ++;
	}
	va_end(args);
	return (ret);
}