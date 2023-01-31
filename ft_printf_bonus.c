/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:32:00 by hasalam           #+#    #+#             */
/*   Updated: 2023/01/30 23:07:43 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_checker(const char *format)
{
	int	i;

	i = 1;
	while (format[i] != 'x' && format[i] != 'X' && format[i] != 'd' && \
		format[i] != 'i')
		i++;
	return (format[i]);
}

static void	ft_putoprator(t_norm *norm, char format, char check, char op)
{
	if (op == '#')
	{
		ft_putchar('0', &norm->counter);
		if (check == 'x')
			ft_putchar('x', &norm->counter);
		else if (check == 'X')
			ft_putchar('X', &norm->counter);
		printformat(norm->ap, format, &norm->counter);
	}
	else if (op == '+')
	{
		ft_putchar('+', &norm->counter);
		printformat(norm->ap, format, &norm->counter);
	}
	else if (op == ' ')
	{
		ft_putchar(' ', &norm->counter);
		printformat(norm->ap, format, &norm->counter);
	}
}

static int	helper1(t_norm *norm, const char *format, char check, int i)
{
	int	n;

	n = 0;
	while (format[i] != 'x' && format[i] != 'X')
	{
		if (format[i] == '#')
			n = 1;
		i++;
	}
	if ((format[i] == 'x' || format[i] == 'X') && n == 1)
		ft_putoprator(norm, format[i], check, '#');
	else
		printformat(norm->ap, format[i], &norm->counter);
	return (i);
}

static int	helper2(t_norm *norm, const char *format, char check, int i)
{
	int	n;
	int	s;

	n = 0;
	s = 0;
	while (format[i] != 'd' && format[i] != 'i')
	{
		if (format[i] == '+')
			n = 1;
		else if (format[i] == ' ')
			s = 1;
		i++;
	}
	if ((format[i] == 'd' || format[i] == 'i') && n == 1)
		ft_putoprator(norm, format[i], check, '+');
	else if ((format[i] == 'd' || format[i] == 'i') && s == 1)
		ft_putoprator(norm, format[i], check, ' ');
	else
		printformat(norm->ap, format[i], &norm->counter);
	return (i);
}

int	ft_printf_bonus(t_norm *norm, const char *format, int i)
{
	char	check;

	check = ft_checker(format);
	if (check == 'x' || check == 'X')
		i = helper1(norm, format, check, i);
	else if (check == 'd' || check == 'i')
		i = helper2(norm, format, check, i);
	return (i);
}
