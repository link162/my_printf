#include "libftprintf.h"

char hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return '0' + v;
	else
		return 'a' + v - 10;
}
void	ft_bzero(void *destination, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = destination;
	while (i < n)
	{
		*(ptr + i) = '\0';
		i++;
	}
}

void	print_address_hex(void* p0)
{
	int i;
	int counter;
	counter = 1;
	intptr_t p = (intptr_t)p0;
	char str[255];

	ft_bzero(str, 255);
	str[0] = '0';
	str[1] = 'x';
	i = (sizeof(p) << 3) - 4;
	while (i >= 0)
	{
		if (counter == 1)
		{
			while (hex_digit((p >> i) & 0xf) == '0')
				i -= 4;
			counter = 2;
		}
	str[counter++] = hex_digit((p >> i) & 0xf);
	i -= 4;
	}
	print_ptr(str);
}


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
