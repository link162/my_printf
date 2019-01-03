#include "libftprintf.h"

int	ft_octal(unsigned long long nbr, char *str)
{
	int i;

	i = 0;
	if (nbr >= 8)
		i = ft_octal(nbr / 8, str);
	str[i] = (nbr % 8) + 48;
	return (1 + i);
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
	ft_octal(nbr, str);
	int_len = ft_str_len(str);
	free_place_before_nbr = 0;
	nulls_before_nbr = 0;
	if (int_len <= g_flags.precision)
		nulls_before_nbr = g_flags.precision - int_len - (g_flags.flag[4] == '#' ? 1 : 0);
	if (int_len <= g_flags.width || g_flags.precision < g_flags.width)
		free_place_before_nbr = int_len >= g_flags.precision ? g_flags.width - int_len : g_flags.width - g_flags.precision;
	if (free_place_before_nbr > 0 && g_flags.flag[4] == '#' && nbr != 0)
		free_place_before_nbr -= 1;
	if (g_flags.flag[0] == '-')
		print_first_oct(str, nulls_before_nbr, free_place_before_nbr);
	else
		print_last_oct(str, nulls_before_nbr, free_place_before_nbr);
}
