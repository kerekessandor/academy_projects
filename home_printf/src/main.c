#include "../includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	unsigned int a, b;

	a = ft_printf("%X %s", 125, "bunica");
	printf("\n");
	printf("----FT_PRINTF----\n");
	b = printf("%X %s", 125, "bunica");
	printf("\n");
	printf("-----PRINTF-----\n");
	printf("\na = %d\nb = %d\n", a, b);
	return(0);
}
