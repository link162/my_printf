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
		ft_putchar(c);
		while (i++ < free_place)
			ft_putchar(' ');
	}
	else
	{
		while (i ++ < free_place)
			ft_putchar(' ');
		ft_putchar(c);
	}
}

void	print_str(char *str)
{
	int str_len;
	int free_place;

	str_len = ft_str_len(str);
	if
}
