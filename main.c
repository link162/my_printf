/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:23:12 by ybuhai            #+#    #+#             */
/*   Updated: 2018/12/11 18:00:05 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main(void)
{
		int i = printf("w%10iorld\n", 42);
		int j = ft_printf("w%10iorld\n", 42);

	printf("origin-%i\nmy    -%i\n", i, j);
}
