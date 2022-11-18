/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 04:55:13 by himejjad          #+#    #+#             */
/*   Updated: 2022/11/18 05:15:07 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		n = nb * (-1);
		i++;
	}
	else
		n = nb;
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar((n % 10) + 48);
	}
	if (n < 10)
		i += ft_putchar(n + 48);
	return (i);
}
