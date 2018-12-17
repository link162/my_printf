#include "libftprintf.h"

void	print_int(int nbr)
{
	int intlen;
	int nulls_before_nbr;
	int	free_place_before_nbr;

	free_place_before_nbr = 0;
	nulls_before_nbr = 0;
	intlen = intlen(nbr);
	if (intlen <= g_flags.precision)
		nulls_before_nbr = g_flags.precision - intlen;
	if (intlen <= g_flags.width || g_flags.precision <= g_flags.width)


}
