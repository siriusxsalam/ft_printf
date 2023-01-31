/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:32:35 by hasalam           #+#    #+#             */
/*   Updated: 2023/01/31 16:15:46 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printformat(va_list ap, char format, int *counter)
{
	if (format == '%')
		ft_putchar('%', counter);
	else if (format == 'p')
		ft_putpointer(va_arg(ap, unsigned long int), counter);
	else if (format == 'u')
		ft_putunsg(va_arg(ap, unsigned int), counter);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(ap, int), counter);
	else if (format == 'c')
		ft_putchar(va_arg(ap, int), counter);
	else if (format == 's')
		ft_putstr(va_arg(ap, char *), counter);
	else if (format == 'x')
		ft_putluhex(va_arg(ap, unsigned int), counter, 0);
	else if (format == 'X')
		ft_putluhex(va_arg(ap, unsigned int), counter, 1);
	else
		ft_putchar(format, counter);
}

static int	helper(t_norm *norm, const char *format)
{
	int	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
		{
			i++;
			break ;
		}
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '#' || format[i] == ' ' || format[i] == '+')
				i = ft_printf_bonus(norm, format, i);
			else
				printformat(norm->ap, format[i], &norm->counter);
		}
		else
			ft_putchar(format[i], &norm->counter);
	}
	return (norm->counter);
}

int	ft_printf(const char *format, ...)
{
	t_norm	norm;

	va_start(norm.ap, format);
	norm.counter = 0;
	norm.counter = helper(&norm, format);
	va_end(norm.ap);
	return (norm.counter);
}
