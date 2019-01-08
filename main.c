#include "ft_printf.h"

int main(void)
{
	int o;
	int m;

	o = printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string");
	m = ft_printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string");
	printf("origin = %i\nmy     = %i\n", o, m);
}
