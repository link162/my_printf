#include "ft_printf.h"

int main(void)
{
	int o;
	int m;

	o = printf("%hh+do\n", 42);	
	m = ft_printf("%hh+dm\n", 42);
	printf("origin = %i\nmy     = %i\n", o, m);
}
