/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:04:35 by ybuhai            #+#    #+#             */
/*   Updated: 2018/12/18 12:50:50 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_first_c(int c, int free_place)
{
	int i;

	ft_putchar(c);
	i = 0;
	while (i++ < free_place)
		ft_putchar(' ');
}

static void	print_last_c(int c, int free_place)
{
	int i;

	i = 0;
	while (i++ < free_place)
		ft_putchar(' ');
	ft_putchar(c);
}

void	print_char(int nbr)
{
	int	free_place_before_nbr;

	free_place_before_nbr = 0;
	if (g_flags.width > 1)
		free_place_before_nbr = g_flags.width - 1;
	if (g_flags.flag[0] == '-')
		print_first_c(nbr, free_place_before_nbr);
	else
		print_last_c(nbr, free_place_before_nbr);
}
