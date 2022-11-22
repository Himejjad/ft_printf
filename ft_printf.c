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

int	ft_print_adr(unsigned long n)
{
	char			*hex;
	int	i;

	 i = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		i += ft_print_adr(n / 16);
		i += ft_print_adr(n % 16);
	}
	else
		i += ft_putchar(hex[n]);
	return (i);
}

int	ft_adr(unsigned long n)
{
	int i;

	i = 2;
	ft_putstr("0x");
	i += ft_print_adr(n);
	return (i);
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

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		x;

	va_start (args, format);
	x = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			x += ft_check(*format, args);
		}
		else
			x += ft_putchar(*format);
		format++;
	}
	va_end (args);
	return (x);
}
// int main ()
// {
// 	int i;
// 	i += 1;
// 	int *ptr;
// 	ptr = &i;
// 	ft_printf("%u\n", *ptr);
// 	printf("%u", *ptr);
// }

