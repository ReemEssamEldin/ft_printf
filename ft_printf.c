/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:00:58 by reldahli          #+#    #+#             */
/*   Updated: 2024/02/19 11:01:00 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	handle_flag(char symbol, va_list *args)
{
	if (symbol == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (symbol == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (symbol == 'd' || symbol == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (symbol == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	else if (symbol == 'x')
		return (ft_puthex((long unsigned int) va_arg(*args, unsigned int), 0));
	else if (symbol == 'X')
		return (ft_puthex((long unsigned int) va_arg(*args, unsigned int), 1));
	else if (symbol == '%')
		return (ft_putchar('%'));
	else if (symbol == 'p')
		return (ft_putptr(va_arg(*args, long long unsigned int)));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		result;

	va_start(args, format);
	i = 0;
	result = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			result += handle_flag(format[++i], &args);
			if (result == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(format[i]) == -1)
				return (-1);
			result++;
		}
		i++;
	}
	va_end(args);
	return (result);
}
