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

int		check_flags(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
	{
		while (str[i] == '-')
			i++;
		g_flags.flag = '-';
		return (i);
	}
	else if (str[i] == '+')
	{
		while (str[i] == '+')
			i++;
		g_flags.flag = '+';
		return (i);
	}
	else if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
		g_flags.flag = ' ';
		return (i);
	}
	return (check_flags2(str));
}

void	check_specified(const char *str, va_list argptr)
{
	int i;

	i = 1;
	i += check_flags(&str[i]);
	i += check_width(&str[i]);
	printf("%i\n", va_arg(argptr, int));
}

int		ft_printf(const char *format, ...)
{
	va_list argptr;
	int		i;

	i = 0;
	struct_to_nul();
	va_start(argptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				ft_putchar(format[i++]);
			else
				check_specified(&format[i], argptr); 
		}
		else
		{
			g_count++;
			ft_putchar(format[i]);
		}
		i++;
	}
	va_end(argptr);
	return (g_count);
}
