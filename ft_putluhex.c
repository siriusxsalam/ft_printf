/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putluhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:40:01 by hasalam           #+#    #+#             */
/*   Updated: 2022/12/02 15:49:21 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putluhex(unsigned int nb, int *counter, int flag)
{
	char	*lhex;
	char	*uhex;

	lhex = "0123456789abcdef";
	uhex = "0123456789ABCDEF";
	if (flag == 0)
	{
		if (nb < 16 && nb >= 0)
			ft_putchar(lhex[nb], counter);
		else
		{
			ft_putluhex(nb / 16, counter, flag);
			ft_putchar(lhex[nb % 16], counter);
		}
	}
	else
	{
		if (nb < 16 && nb >= 0)
			ft_putchar(uhex[nb], counter);
		else
		{
			ft_putluhex(nb / 16, counter, flag);
			ft_putchar(uhex[nb % 16], counter);
		}
	}
}
