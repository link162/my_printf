/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:34:14 by ybuhai            #+#    #+#             */
/*   Updated: 2018/11/07 18:42:11 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *destination, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = destination;
	while (i < n)
	{
		*(ptr + i) = '\0';
		i++;
	}
}