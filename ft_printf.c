/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 04:55:04 by himejjad          #+#    #+#             */
/*   Updated: 2022/11/18 05:03:17 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len2(unsigned long int n)
{
	int	x;

	x = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
	}
	while (n > 0)
	{
		x++;
		n /= 16;
	}
	return (x);
}


int	ft_print_adr(unsigned long n)
{
	char			*hex;
	unsigned long	x;

	x = n;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ft_print_adr(n / 16);
		ft_print_adr(n % 16);
	}
	else
		write(1, &hex[n], 1);
	return (len(x));
}

int	ft_adr(unsigned long n)
{
	ft_putstr("0x");
	ft_print_adr(n);
	return (len2(n) + 2);
}

int	ft_check(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_adr(va_arg(args, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_unsputnbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_hexalow(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_hexaup(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		x;
	char	*format;

	format = (char *)s;
	va_start (args, s);
	x = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (x);
			x += ft_check(*format, args);
		}
		else
			x += ft_putchar(*format);
		format++;
	}
	va_end (args);
	return (x);
}
