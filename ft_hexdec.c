/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 04:55:00 by himejjad          #+#    #+#             */
/*   Updated: 2022/11/18 05:27:12 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalow(unsigned int n)
{
	char			*hex;
	int				i;

	i = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		i += ft_hexalow(n / 16);
		i += ft_hexalow(n % 16);
	}
	else
		i += ft_putchar(hex[n]);
	return (i);
}

int	ft_hexaup(unsigned int n)
{
	char			*hex;
	int				i;

	i = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		i += ft_hexaup(n / 16);
		i += ft_hexaup(n % 16);
	}
	else
		i += ft_putchar(hex[n]);
	return (i);
}
