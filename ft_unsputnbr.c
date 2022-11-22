/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsputnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:12:18 by himejjad          #+#    #+#             */
/*   Updated: 2022/11/18 05:14:55 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsputnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
	{
		i += ft_unsputnbr(nb / 10);
		i += ft_unsputnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}
