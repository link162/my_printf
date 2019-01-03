/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:17:11 by ybuhai            #+#    #+#             */
/*   Updated: 2018/12/28 17:22:32 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
static void	float_init(long double num, unsigned int *i, int *f, char *res)
{
	*i = 0;
	if (num < 0.0)
	{
		*f = -1;
		res[0] = '-';
		(*i)++;
	}
}

static unsigned int	ft_getdouble_len(long double value, long double *limit)
{
	unsigned int len;

	len = 2;
	*limit = 1;
	if (value < 0)
		len++;
	while (value > 10 || value < -10)
	{
		len++;
		value = value / 10;
		*limit = (*limit) * 10;
	}
	return (len);
}

static int		get_float_bit(long double num, long double limit)
{
	long double	temp;
	int			i;

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


static char	*ftoi(long double nbr, int *f)
{
	unsigned int	i;
	int				t;
	long double		limit;
	unsigned int	len;
	char			*res;
	int 			l;

	len = ft_getdouble_len(nbr, &limit);
	l = g_flags.precision >= 0 ? (unsigned int)g_flags.precision : 6;
	if (g_flags.precision == 0)
		l = -1;
	res = ft_strnew(len + l + 1);
	float_init(nbr, &i, f, res);
	if (g_flags.precision != 0)
		res[len - 1] = '.';
	while (i < len + l)
	{
		if (i == len - 1)
			i++;
		t = get_float_bit((*f) * nbr, limit);
		res[i] = t + '0';
		nbr = nbr - (*f) * limit * t;
		limit = limit / 10;
		i++;
	}
	return (res);
}

void print_double(long double nbr)
{
	char *str;
	int i;
	int nbr_len;
	int n;
	long double f;
	int l;

	l = 1;
	if (g_flags.precision >= 0)
	{
		f = 0.5;
		n = 0;
		while (n++ < g_flags.precision)
			f /= 10;
		if (nbr > 0)
			nbr += f;
		else if (nbr < 0)
			nbr -= f;
	}
	else
	{
		if (nbr < 0)
			nbr -= 0.0000005;
		else if (nbr > 0)
			nbr += 0.0000005;
	}
	str = ftoi(nbr, &l);
	nbr_len = ft_strlen(str);
	if (g_flags.flag[0] == '-')
	{
		i = 0;
		if (nbr >= 0 && g_flags.flag[1] == '+')
		{
			ft_put_char('+');
			g_flags.width--;
		}
		else if (nbr >=0 && g_flags.flag[2] == ' ')
		{
			ft_put_char(' ');
			g_flags.width--;
		}
		while (str[i])
			ft_put_char(str[i++]);
		i = g_flags.width - nbr_len;
		while (i-- > 0)
			ft_put_char(' ');
	}
	else
	{
		i = 0;
		if (str[i] == '-' && g_flags.flag[3] == '0')
			ft_put_char(str[i++]);
		if ((g_flags.flag[1] == '+' || g_flags.flag[2] == ' ') && nbr >= 0)
			g_flags.width--;
		n = g_flags.width - nbr_len;
		if (g_flags.flag[3] == '0' && nbr >= 0)
		{
			if (g_flags.flag[1] == '+')
				ft_put_char('+');
			else if (g_flags.flag[2] == ' ')
				ft_put_char(' ');
		}
		while (n-- > 0)
		{
			if (g_flags.flag[3] == '0')
				ft_put_char('0');
			else
				ft_put_char(' ');
		}
		if (g_flags.flag[3] != '0' && nbr >= 0)
		{
			if (g_flags.flag[1] == '+')
				ft_put_char('+');
			else if (g_flags.flag[2] == ' ')
				ft_put_char(' ');
		}
		while (str[i])
			ft_put_char(str[i++]);
	}
	free(str);
}
