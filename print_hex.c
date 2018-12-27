#include "libftprintf.h"

int	print_16(char *str, __int128 nbr)
{
	int i;

	i = 0;
	if (nbr >= 16)
		i = print_16(str, nbr / 16);
	if (nbr % 16 < 10)
	{
		str[i] = (nbr % 16) + 48;
		return (1 + i);
	}
	else
	{
		if (g_flags.symbol == 'X')
			str[i] = nbr % 16 + 55;
		else
			str[i] = nbr % 16 + 87;
		return (1 + i);
	}
}

void	print_last_hex(char *str, int nulls_before, int free_place)
{
	while (free_place-- > 0)
		ft_putchar(' ');
	if (g_flags.flag[4] == '#' && str[0] != '0')
	{
		ft_putchar('0');
		if (g_flags.symbol == 'x')
			ft_putchar('x');
		else
			ft_putchar('X');
	}
	while (nulls_before-- > 0)
		ft_putchar('0');
	while (*str)
		ft_putchar(*str++);
}

void	print_first_hex(char *str, int nulls_before, int free_place)
{
	if (g_flags.flag[4] == '#' && str[0] != '0')
	{
		ft_putchar('0');
		if (g_flags.symbol == 'x')
			ft_putchar('x');
		else
			ft_putchar('X');
	}
	while (nulls_before-- > 0)
		ft_putchar('0');
	while (*str)
		ft_putchar(*str++);
	while (free_place-- > 0)
		ft_putchar(' ');
}

void	print_hex(__int128 nbr)
{
	char str[256];
	int int_len;
	int free_place_before_nbr;
	int nulls_before_nbr;

	ft_bzero(str, 256);
	print_16(str, nbr);
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
		print_first_hex(str, nulls_before_nbr, free_place_before_nbr);
	else
		print_last_hex(str, nulls_before_nbr, free_place_before_nbr);
}
