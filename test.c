#include "ft_printf.h"

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
	char	*s;

	s = (char *)s;
	va_start (args, s);
	x = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!*s)
				return (x);
			x += ft_check(*s, args);
		}
		else
			x += ft_putchar(*s);
		s++;
	}
	va_end (args);
	return (x);
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
	// char	*s;

	// s = (char *)s;
	va_start (args, s);
	x = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!*s)
				return (x);
			x += ft_check(*s, args);
		}
		else
			x += ft_putchar(*s);
		s++;
	}
	va_end (args);
	return (x);
}