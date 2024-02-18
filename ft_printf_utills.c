#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;
	int	printed;

	count = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	else if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count += 1;
		n = -n;
	}
	printed = 0;
	printed = ft_putunbr(n);
	if (printed == -1)
		return (-1);
	return (count + printed);
}

int	ft_putunbr(unsigned int n)
{
	char	c;
	int		count;
	int		temp;

	count = 0;
	temp = 0;
	if (n > 9)
	{
		temp = ft_putunbr(n / 10);
		if (temp == -1)
			return (-1);
		count += temp;
		temp = ft_putunbr(n % 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	else
	{
		c = n + '0';
		if (ft_putchar(c) == -1)
			return (-1);
		count += 1;
	}
	return (count);
}

int	ft_puthex(unsigned int n, int upper)
{
	char	*charset;
	char	c;
	int		count;
	int		temp;

	count = 0;
	temp = 0;
	if (upper)
		charset = "0123456789ABCDEF";
	else
		charset = "0123456789abcdef";
	count = 0;
	if (n > 15)
	{
		temp = ft_puthex(n / 16, upper);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	c = charset[n % 16];
	if (ft_putchar(c) == -1)
		return (-1);
	count += 1;
	return (count);
}

int	ft_putptr(unsigned long int n)
{
	char	c;
	int		count;

	count = 0;
	if (n > 15)
	{
		count += ft_putptr(n / 16);
		count += ft_putptr(n % 16);
	}
	else
	{
		if (n < 10)
			c = n + '0';
		else
			c = n + 'a' - 10;
		if (ft_putchar(c) == -1)
			return (-1);
		count += 1;
	}
	return (count);
}
