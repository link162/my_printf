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
	str = (char *)malloc(sizeof(char) * (i));
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

char		*ftoi(long double nbr)
{
	char		*str;
	char		*tmp2;
	int			len;
	char*		tmp;
	__int128	res;

	res = (__int128)nbr;
	printf("%u\n", res);
	str = ft_itoa(res);
	printf("***%s***\n", str);
	if (nbr < 0)
	{
		nbr *= -1;
		res *= -1;
	}
	len = g_flags.precision >= 0 ? g_flags.precision : 6;
	if (len)
	{
		tmp = ft_strjoin(str, ".");
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
		while(len)
		{
			nbr -= (long double)res;
			nbr *= 10;
			res = (__int128)nbr;
			tmp = ft_itoa(res);
			tmp2 = ft_strjoin(str, tmp);
			free(tmp);
			free(str);
			str = ft_strdup(tmp2);
			free(tmp2);
			len--;
		}
	}
	return (str);
}

void print_double(long double nbr)
{
	char *str;
	int i;
	int nbr_len;
	int n;
	long double f;

	if (g_flags.precision >= 0)
	{
		f = 0.5;
		i = 0;
		while (i++ < g_flags.precision)
			f /= 10;
		if (nbr > 0)
			nbr += f;
		else if (nbr < 0)
			nbr -= f;
	}
	else
		nbr += 0.0000005;
	str = ftoi(nbr);
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
}
