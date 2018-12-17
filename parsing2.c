#include "libftprintf.h"

int check_length(const char *str)
{
	if(str[0] == 'h')
	{
		if (str[1] == 'h')
			g_flags.length = 2;
		else
			g_flags.length = 1;
	}
	else if (str[0] == 'l')
	{
		if (str[1] == 'l')
			g_flags.length = 4;
		else
			g_flags.length = 3;
	}
	else if (str[0] == 'L')
		g_flags.length = 5;
	if (g_flags.length == 1 || g_flags.length == 3 || g_flags.length == 5)
		return (1);
	else if (g_flags.length == 2 || g_flags.length == 4)
		return (2);
	return (0);
}

int		check_symbol(char c)
{
	if (c == 'd' || c == 'i' || c == 's' || c == 'c' || c == 'f' || c == 'u'
					|| c == 'o' || c == 'x' || c == 'X' || c == 'F' || c == 'e'
					|| c == 'E' || c == 'g' || c == 'G' || c == 'a' || c == 'A'
					|| c == 'p' || c == 'n')
		g_flags.symbol = c;
	else
		return (0);
	return (1);
}
