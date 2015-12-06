#include "../includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	unsigned int a, b;

	a = ft_printf("Ma numesc %s si am %d %s", "andrei", 23 ,"ani");
	printf("\n");
	printf("----FT_PRINTF----\n");
	b = printf("Ma numesc %s si am %d %s", "andrei", 23 ,"ani");
	printf("\n");
	printf("-----PRINTF-----\n");
	printf("\na = %d\nb = %d\n", a, b);
	return(0);
}
