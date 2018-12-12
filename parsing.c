/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:52:41 by ybuhai            #+#    #+#             */
/*   Updated: 2018/12/12 14:32:37 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	struct_to_nul(void)
{
	g_flags.flag = 0;
	g_flags.width = 0;
}

int		intlen(int n)
{
	int	j;

	j = 1;
	if (n < 0)
		j++;
	while (n /= 10)
		j++;
	return (j);
}

int		ft_atoi(const char *str)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
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
	printf("%i\n", i);
	return (i);
}
