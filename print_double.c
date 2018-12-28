/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:17:11 by ybuhai            #+#    #+#             */
/*   Updated: 2018/12/28 08:11:48 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	else
		return (0);
}


static int	count_ch(__int128 n)
{
	int	j;

	j = 2;
	if (n < 0)
		j++;
	while (n /= 10)
		j++;
	return (j);
}

char		*ft_itoa(__int128 n)
{
	int		i;
	char	*str;

	i = count_ch(n);
	str = (char *)malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	ft_bzero(str, i);
	i -= 2;
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		if (n > 0)
			str[i] = (n % 10) + 48;
		else
			str[i] = -(n % 10) + 48;
		i--;
		n = n / 10;
	}
	return (str);
}

char *ftoi(long double nbr)
{
	char *str;
	char pos;
	char len;
	char* curr;
	__int128 res;
	nbr += 0.0000005;
	pos = 0;

	res = (__int128)nbr;  
	str = ft_itoa(res);
	if (nbr < 0)
	{
		nbr *= -1;
		res *= -1;
	}
	len = ft_str_len(str); 
	pos = len;
	str[pos++] = '.';  
	while(pos < (len + 7) )  
	{
		nbr = nbr - (double)res;  
		nbr *= 10;  
		res = (int)nbr;  
		curr = ft_itoa(res); 
		str[pos++] = *curr;
	}
	return (str);
}
  
void print_double(long double nbr)
{
	char *str = ftoi(nbr);
	int i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}
