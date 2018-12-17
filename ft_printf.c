/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:38:09 by ybuhai            #+#    #+#             */
/*   Updated: 2018/12/11 18:06:46 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	g_count++;
	write(1, &c, 1);
}

int		check_flags2(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '#')
	{
		while (str[i] == '#')
			i++;
		g_flags.flag = '#';
	}
	else if (str[i] == '0')
	{
		while (str[i] == '0')
			i++;
		g_flags.flag = '0';
	}
	return (i);
}

int		check_flags(char c)
{
	static int i;
	if (i > 4)
		return (0);
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
	{
		g_flags.flag[i++] = c;
		return (1);
	}
	return (0);
}

int	check_specified(const char *str, va_list argptr)
{
	int i;

	struct_to_nul();
	i = 1;
	while (check_flags(str[i]))
			i++;
	i += check_width(&str[i]);
	i += check_precision(&str[i]);
	i += check_length(&str[i]);
	check_symbol(str[i]);
//		return (0); //add error case
	prepare_to_print(argptr);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list argptr;
	int		i;

	i = 0;
	va_start(argptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				ft_putchar(format[i++]);
			else
				i += check_specified(&format[i], argptr); 
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(argptr);
	return (g_count);
}
