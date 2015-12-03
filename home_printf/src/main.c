#include "../includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("%#x", 0);
	printf("\n");
	printf("----FT_PRINTF----\n");
	printf("%#x", 0);
	printf("\n");
	printf("-----PRINTF-----\n");
	return(0);
}
