/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:24:58 by hasalam           #+#    #+#             */
/*   Updated: 2023/01/30 22:43:47 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_norm
{
	va_list	ap;
	int		counter;
}	t_norm;

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *counter);
void	ft_putluhex(unsigned int nb, int *counter, int flag);
void	ft_putnbr(int nb, int *counter);
void	ft_putpointer(unsigned long int nb, int *counter);
void	ft_putstr(char *str, int *counter);
void	ft_putunsg(unsigned int nb, int *counter);
void	printformat(va_list ap, char format, int *counter);
int		ft_printf_bonus(t_norm *norm, const char *format, int i);

#endif