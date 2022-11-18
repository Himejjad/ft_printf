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

int	len(long int n)
{
	int	x;

	x = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		x++;
		n /= 16;
	}
	return (x);
}

int	ft_hexalow(unsigned int n)
{
	char			*hex;
	unsigned int	i;

	i = n;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ft_hexalow(n / 16);
		ft_hexalow(n % 16);
	}
	else
		write(1, &hex[n], 1);
	return (len(i));
}

int	ft_hexaup(unsigned int n)
{
	char			*hex;
	unsigned int	i;

	i = n;
	hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_hexaup(n / 16);
		ft_hexaup(n % 16);
	}
	else
		write(1, &hex[n], 1);
	return (len(i));
}
