#include "ft_printf.h"

int	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s && s[len] != '\0')
		len ++;
	if (len != 0)
		write(1, s, len);
	return (len);
}

int	ft_putnbr(int n, int size)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			return (11);
		}
		size += write(1, "-", 1);
		n = n * -1;
	}
	if (n / 10 > 0)
		size += ft_putnbr(n / 10, 1);
	ft_putchar(n % 10 + '0');
	return (size);
}

int	ft_putunsigned(unsigned int n, int size)
{
	if (n / 10 > 0)
		size += ft_putunsigned(n / 10, size);
	ft_putchar(n % 10 + '0');
	return (size);
}

int	ft_hexa(long long int n, int size, int up)
{
	if (n < 0)
		n = n + 4294967296;
	if (n / 16 > 0)
		size += ft_hexa(n / 16, 1, up);
	if (n % 16 > 9 && up == 1)
		ft_putchar(n % 16 + 'A' - 10);
	else if (n % 16 > 9 && up == 0)
		ft_putchar(n % 16 + 'a' - 10);
	else
		ft_putchar(n % 16 + '0');
	return (size);
}