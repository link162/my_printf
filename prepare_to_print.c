#include "libftprintf.h"

void	prepare_to_print(va_list argptr)
{
	if (g_flags.symbol == 'i' || g_flags.symbol == 'd')
		print_int(va_arg(argptr, int));
	else if (g_flags.symbol == 'c')
		print_char(va_arg(argptr, int));
	else if (g_flags.symbol == 's')
		print_str(va_arg(argptr, char *));
}
