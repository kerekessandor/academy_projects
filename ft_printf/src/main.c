#include "../includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	unsigned int a, b;

	a = ft_printf("%#22.2X", 232);
	printf("\n");
	printf("----FT_PRINTF----\n");
	b = printf("%#22.2X", 232);
	printf("\n");
	printf("-----PRINTF-----\n");
	printf("\na = %d\nb = %d\n", a, b);
	return(0);
}
