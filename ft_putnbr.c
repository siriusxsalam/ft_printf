/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:43:36 by hasalam           #+#    #+#             */
/*   Updated: 2022/12/01 12:04:09 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *counter)
{
	long long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putchar('-', counter);
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + '0', counter);
	}
	else
	{
		ft_putnbr(nbr / 10, counter);
		ft_putchar((nbr % 10) + '0', counter);
	}
}
