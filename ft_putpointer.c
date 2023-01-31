/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:49:32 by hasalam           #+#    #+#             */
/*   Updated: 2022/12/01 21:48:48 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned long int nb, int *counter)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(hex[nb], counter);
	else
	{
		ft_puthex(nb / 16, counter);
		ft_putchar(hex[nb % 16], counter);
	}
}

void	ft_putpointer(unsigned long int nb, int *counter)
{
	ft_putchar('0', counter);
	ft_putchar('x', counter);
	ft_puthex(nb, counter);
}
