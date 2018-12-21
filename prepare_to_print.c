#include "libftprintf.h"

void	prepare_po_print2(va_list argptr)
{
	
}

void	prepare_to_print(va_list argptr)
{
	if ((g_flags.symbol == 'i' || g_flags.symbol == 'd') && g_flags.length == 0)
		print_int(va_arg(argptr, int));
	else if ((g_flags.symbol == 'i' || g_flags.symbol == 'd') && g_flags.length == 1)
		print_int((short)va_arg(argptr, int));
	else if ((g_flags.symbol == 'i' || g_flags.symbol == 'd') && g_flags.length == 2)
		print_int((signed char)va_arg(argptr, int));
	else if ((g_flags.symbol == 'i' || g_flags.symbol == 'd') && g_flags.length == 3)
		print_int(va_arg(argptr, long));
	else if ((g_flags.symbol == 'i' || g_flags.symbol == 'd') && g_flags.length == 4)
		print_int(va_arg(argptr, long long int));
	else if (g_flags.symbol == 'c')
		print_char((char)va_arg(argptr, int));
	else if (g_flags.symbol == 's')
		print_str(va_arg(argptr, char *), 0);
	else if (g_flags.symbol == 'u' && g_flags.length == 0)
		print_int(va_arg(argptr, unsigned int));
	else if (g_flags.symbol == 'u' && g_flags.length == 2)
		print_int((unsigned char)va_arg(argptr, int));
	else if (g_flags.symbol == 'u' && g_flags.length == 1)
		print_int((unsigned short)va_arg(argptr, int));
	else if (g_flags.symbol == 'u' && g_flags.length == 3)
		print_int(va_arg(argptr, unsigned long));
//	else
//		prepare_to_print2(argptr);
}
