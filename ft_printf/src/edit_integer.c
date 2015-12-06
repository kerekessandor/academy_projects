#include "../includes/ft_printf.h"

int		edit_di_integer(va_list *ap, t_flag flag)
{
	int nbr;
	char *text;

	nbr = va_arg(*ap, int);
	(void)flag;
	text = ft_itoa(nbr);
	ft_putstr(text);
	return(ft_strlen(text));
}