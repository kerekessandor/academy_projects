#include "../includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("%20s", "nimic");
	printf("\n");
	printf("----FT_PRINTF----\n");
	printf("%20s", "nimic");
	printf("\n");
	printf("-----PRINTF-----\n");
	return(0);
}
