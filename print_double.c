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

#include "libftprintf.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = ft_str_len(src);
	dest = malloc(sizeof(*dest) * (i + 1));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t r;
	size_t n;

	n = 0;
	r = 0;
	while (dest[n] != '\0')
		n++;
	while (src[r] != '\0')
	{
		dest[n] = src[r];
		r++;
		n++;
	}
	dest[n] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	n = ft_str_len(s1) + ft_str_len(s2) + 1;
	str = (char *)malloc(sizeof(*s1) * n);
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}

int		ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	else
		return (0);
}

void	float_init(long double num, unsigned int *i, int *f, char *res)
{
	*i = 0;
	if (num < 0.0)
	{
		*f = -1;
		res[0] = '-';
		(*i)++;
	}
}

unsigned int	ft_getdouble_len(long double value, long double *limit)
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

void	*ft_memset(void *destination, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = destination;
	while (i < n)
	{
		*(ptr + i) = c;
		i++;
	}
	return (destination);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	ft_memset(str, (int)'\0', size + 1);
	return (str);
}

int		get_float_bit(long double num, long double limit)
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


char	*ftoi(long double nbr, int *f)
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
	nbr_len = ft_str_len(str);
	if (g_flags.flag[0] == '-')
	{
		i = 0;
		if (nbr >= 0 && g_flags.flag[1] == '+')
		{
			ft_putchar('+');
			g_flags.width--;
		}
		else if (nbr >=0 && g_flags.flag[2] == ' ')
		{
			ft_putchar(' ');
			g_flags.width--;
		}
		while (str[i])
			ft_putchar(str[i++]);
		i = g_flags.width - nbr_len;
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		i = 0;
		if (str[i] == '-' && g_flags.flag[3] == '0')
			ft_putchar(str[i++]);
		if ((g_flags.flag[1] == '+' || g_flags.flag[2] == ' ') && nbr >= 0)
			g_flags.width--;
		n = g_flags.width - nbr_len;
		if (g_flags.flag[3] == '0' && nbr >= 0)
		{
			if (g_flags.flag[1] == '+')
				ft_putchar('+');
			else if (g_flags.flag[2] == ' ')
				ft_putchar(' ');
		}
		while (n-- > 0)
		{
			if (g_flags.flag[3] == '0')
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		if (g_flags.flag[3] != '0' && nbr >= 0)
		{
			if (g_flags.flag[1] == '+')
				ft_putchar('+');
			else if (g_flags.flag[2] == ' ')
				ft_putchar(' ');
		}
		while (str[i])
			ft_putchar(str[i++]);
	}
	free(str);
}
