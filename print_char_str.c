/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:04:35 by ybuhai            #+#    #+#             */
/*   Updated: 2018/12/18 13:28:58 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_str_len(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	print_ptr(char *str)
{
	int		i;
	int		str_len;
	int		free_place;
	int		nulls_before;

	i = 0;
	free_place = 0;
	str_len = ft_str_len(str);
	if (g_flags.precision > str_len - 2)
		nulls_before = g_flags.precision - str_len + 2;
	if (g_flags.width > str_len || g_flags.width > g_flags.precision + 2)
		free_place = str_len > g_flags.precision + 2 ? g_flags.width - str_len : g_flags.width - g_flags.precision - 2;
	if (g_flags.flag[0] == '-')
	{
		while (i < 2)
			ft_putchar(str[i++]);
		i = 0;
		while (i++ < nulls_before)
			ft_putchar('0');
		i = 2;
		while (i < str_len)
			ft_putchar(str[i++]);
		while (free_place--)
			ft_putchar(' ');
	}
	else
	{
		while (free_place--)
			ft_putchar(' ');
		while (i < 2)
			ft_putchar(str[i++]);
		i = 0;
		while (i++ < nulls_before)
			ft_putchar('0');
		i = 2;
		while (i < str_len)
			ft_putchar(str[i++]);
	}
}


void	print_char(int nbr)
{
	int	free_place;
	int i;

	i = 0;
	free_place = 0;
	if (g_flags.width > 1)
		free_place = g_flags.width - 1;
	if (g_flags.flag[0] == '-')
	{
		ft_putchar(nbr);
		while (i++ < free_place)
			ft_putchar(' ');
	}
	else
	{
		while (i ++ < free_place)
			ft_putchar(' ');
		ft_putchar(nbr);
	}
}

void	print_str(char *str)
{
	int		i;
	int		str_len;
	int		free_place;
	int		lenght;

	i = 0;
	free_place = 0;
	str_len = ft_str_len(str);
	lenght = str_len;
	if (g_flags.precision >= 0 && g_flags.precision < str_len)
			lenght = g_flags.precision;
	if (g_flags.width > str_len)
		free_place = g_flags.width - lenght;
	if (g_flags.flag[0] == '-')
	{
		while (i < lenght)
			ft_putchar(str[i++]);
		while (free_place--)
			ft_putchar(' ');
	}
	else
	{
		while (free_place--)
			ft_putchar(' ');
		while (i < lenght)
			ft_putchar(str[i++]);
	}
}
