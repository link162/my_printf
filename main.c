#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int o;
	int m;
	double x = 42.1113;
	o = printf("%20.4fo\n", x);
	m = ft_printf("%20.4fm\n", x);
	printf("origin = %i\nmy     = %i\n", o, m);
}
