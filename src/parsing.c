/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:52:41 by ybuhai            #+#    #+#             */
/*   Updated: 2019/01/08 22:07:13 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	struct_to_nul(void)
{
	int i;

	i = 0;
	while (i < 5)
		g_flags.flag[i++] = 0;
	g_flags.width = -1;
	g_flags.symbol = 0;
	g_flags.precision = -1;
	g_flags.length = 0;
}

int		intlen(__int128 n)
{
	int	j;

	j = 1;
	if (n < 0)
		j++;
	while (n /= 10)
		j++;
	return (j);
}

int		check_precision(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '.')
	{
		if (str[1] < '0' || str[1] > '9')
			return (-1);
		g_flags.precision = ft_atoi(&str[1]);
		i = intlen(g_flags.precision) + 1;
	}
	return (i);
}

int		check_width(const char *str)
{
	int i;

	i = 0;
	if (str[i] >= '1' && str[i] <= '9')
	{
		g_flags.width = ft_atoi(str);
		i = intlen(g_flags.width);
	}
	return (i);
}

int		get_float_bit(long double num, long double limit)
{
	long double		temp;
	int				i;

	temp = num / limit;
	i = 1;
	while (i < 10)
	{
		if (temp < i)
			return (i - 1);
		i++;
	}
	return (9);
}
