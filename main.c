/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:23:12 by ybuhai            #+#    #+#             */
/*   Updated: 2018/12/12 14:33:45 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main(void)
{
		int i = printf("wo\trld\n");
		int j = ft_printf("wo\trld\n");

	printf("origin-%i\nmy    -%i\n", i, j);
}
