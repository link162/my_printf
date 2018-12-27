/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:17:11 by ybuhai            #+#    #+#             */
/*   Updated: 2018/12/27 20:21:26 by ybuhai           ###   ########.fr       */
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

char * myfloat(long double f)
{

	char size = '4';
	char *str;
	char pos;  // position in string
	char len;  // length of decimal part of result
	char* curr;  // temp holder for next digit
	int value;  // decimal digit(s) to convert

	f += 0.0000005;
	pos = 0;  // initialize pos, just to be sure

	value = (__int128)f;  // truncate the floating point number
	str = ft_itoa(value);  // this is kinda dangerous depending on the length of str
	// now str array has the digits before the decimal
	if (f < 0 )  // handle negative numbers
	{
		f *= -1;
		value *= -1;
	}


	len = ft_str_len(str);  // find out how big the integer part was
	pos = len;  // position the pointer to the end of the integer part
	str[pos++] = '.';  // add decimal point to string

	while(pos < (len + 7) )  // process remaining digits
	{
		f = f - (double)value;  // hack off the whole part of the number
		f *= 10;  // move next digit over
		value = (int)f;  // get next digit
		curr = ft_itoa(value); // convert digit to string
		str[pos++] = *curr; // add digit to result string and increment pointer
	}
	return (str);
}

char * mygfloat(double f)
{
    char *str;
    int size = 2;
    unsigned char pos;
    char len;
    char* curr;
    int value;

    pos = 0;
	//f += 0.005;
    value = (int)f;
    str = ft_itoa(value);


    if (f < 0 )
    {
        f *= -1;
        value *= -1;
    }

    len = ft_str_len(str);
    pos = len;
    str[pos++] = '.';
    while(pos < (size + len + 1) )
    {
        f = f - (float)value;
        f *= 10;
        curr = ft_itoa(value);
        str[pos++] = *curr;
    }
    pos = 0;
    while(str[pos])
    {
        if (!(ft_isdigit(str[pos])) && str[pos] != '.')
            str[pos] = '\0';
        pos++;
    }
    return (str);
}

void print_double(long double nbr)
{
	char *str = myfloat(nbr);
	int i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}
