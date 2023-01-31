/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:30:50 by hasalam           #+#    #+#             */
/*   Updated: 2022/12/01 12:52:04 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsg(unsigned int nb, int *counter)
{
	if (nb < 10)
		ft_putchar(nb + '0', counter);
	else
	{
		ft_putunsg(nb / 10, counter);
		ft_putchar((nb % 10) + '0', counter);
	}
}
