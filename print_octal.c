#include "libftprintf.h"

void	ft_reverse(char *str)
{
	char	tmp;
	int		it;
	int 	len;

	len = ft_str_len(str);
	it = -1;
	while (++it < (len / 2))
	{
		tmp = str[it];
		str[it] = str[len - it - 1];
		str[len - it - 1] = tmp;
	}
}

void	ft_octal_itoa(unsigned long long n, char *str)
{
	int 			it;
	unsigned int	tmp;

	it = 0;
	while (n)
	{
		str[it] = tmp % 8 + '0';
		tmp = tmp / 8;
		it++;
	}
	ft_reverse(str);
}

void	print_last_oct(char *str, int nulls_before, int free_place)
{
	while (free_place-- > 0)
		ft_putchar(' ');
	if (g_flags.flag[4] == '#' && str[0] != '0')
		ft_putchar('0');
	while (nulls_before-- > 0)
		ft_putchar('0');
	while (*str)
		ft_putchar(*str++);
}

void	print_first_oct(char *str, int nulls_before, int free_place)
{
	if (g_flags.flag[4] == '#' && str[0] != '0')
		ft_putchar('0');
	while (nulls_before-- > 0)
		ft_putchar('0');
	while (*str)
		ft_putchar(*str++);
	while (free_place-- > 0)
		ft_putchar(' ');
}

void	print_octal(unsigned long long nbr)
{
	int int_len;
	int free_place_before_nbr;
	int nulls_before_nbr;
	char str[25];

	ft_bzero(str, 25);
	ft_octal_itoa(nbr, str);
	int_len = ft_str_len(str);
	free_place_before_nbr = 0;
	nulls_before_nbr = 0;
	if (int_len <= g_flags.precision)
		nulls_before_nbr = g_flags.precision - int_len;
	if (int_len <= g_flags.width || g_flags.precision < g_flags.width)
		free_place_before_nbr = int_len >= g_flags.precision ? g_flags.width - int_len : g_flags.width - g_flags.precision;
	if (free_place_before_nbr > 0 && g_flags.flag[4] == '#' && nbr != 0)
		free_place_before_nbr -= 2;
	if (g_flags.flag[0] == '-')
		print_first_oct(str, nulls_before_nbr, free_place_before_nbr);
	else
		print_last_oct(str, nulls_before_nbr, free_place_before_nbr);
}
