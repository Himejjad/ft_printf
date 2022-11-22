/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 04:55:07 by himejjad          #+#    #+#             */
/*   Updated: 2022/11/18 05:15:33 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putstr(char *s);
int	ft_unsputnbr(unsigned int nb);
int	ft_hexalow(unsigned int n);
int	ft_hexaup(unsigned int n);
int	ft_printf(const char *s, ...);
int	ft_check(char c, va_list args);
int	ft_adr(unsigned long n);
int	ft_print_adr(unsigned long n);

#endif