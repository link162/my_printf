#include "libftprintf.h"

void	ft_putnbr(__int128 x)
{
	if (x > 9)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	if (x < 10 )
		ft_putchar(x + 48);
}

void	print_first_nbr(__int128 nbr, int nulls_before, int free_place)
{
	int i;

	if (g_flags.flag[1] == '+' && nbr >= 0)
	{
		ft_putchar('+');
		free_place--;
	}
	else if (g_flags.flag[2] == ' ' && nbr >= 0)
	{
		ft_putchar(' ');
		free_place--;
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	i = 0;
	while (i++ < nulls_before)
		ft_putchar('0');
	ft_putnbr(nbr);
	i = 0;
	while (i++ < free_place)
		ft_putchar(' ');
}

void	print_last_nbr(__int128 nbr, int nulls_before, int free_place)
{
	int i;

	i = 0;
	if ((g_flags.flag[1] == '+' || g_flags.flag[2] == ' ') && nbr >= 0)
		free_place--;
	while (i++ < free_place)
		if (g_flags.flag[3] == '0')
			ft_putchar('0');
		else
			ft_putchar(' ');
	if (g_flags.flag[1] == '+' && nbr >= 0)
		ft_putchar('+');
	else if (g_flags.flag[2] == ' ' && nbr >= 0)
		ft_putchar(' ');
	else if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	i = 0;
	while (i++ < nulls_before)
		ft_putchar('0');
	ft_putnbr(nbr);
}

void	print_int(__int128 nbr)
{
	int int_len;
	int nulls_before_nbr;
	int	free_place_before_nbr;

	free_place_before_nbr = 0;
	nulls_before_nbr = 0;
	int_len = intlen(nbr);
	if (nbr < 0)
			int_len--;
	if (g_flags.precision >= 0)
		g_flags.flag[3] = 0;
	if (int_len < g_flags.precision)
		nulls_before_nbr = g_flags.precision - int_len;
	if (int_len + (nbr < 0 ? 1 : 0) + nulls_before_nbr < g_flags.width)
		free_place_before_nbr = g_flags.width - int_len - (nbr < 0 ? 1 : 0) - nulls_before_nbr;
	if (g_flags.flag[0] == '-')
		print_first_nbr(nbr, nulls_before_nbr, free_place_before_nbr);
	else
		print_last_nbr(nbr, nulls_before_nbr, free_place_before_nbr);
}
