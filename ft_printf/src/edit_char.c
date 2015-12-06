#include "../includes/ft_printf.h"

int		edit_c_char(va_list *ap, t_flag flag)
{
	char *spaces;
	char chr;

	chr = va_arg(*ap, int);
	if (flag.width > 1)
	{
		spaces = ft_memalloc(flag.width - 1);
		spaces = ft_memset(spaces, ' ', flag.width - 1);
		if (flag.has_minus == 1)
		{
			ft_putchar(chr);
			ft_putstr(spaces);
		}
		else
		{
			ft_putstr(spaces);	
			ft_putchar(chr);
		}
		return(flag.width);
	}
	else
		ft_putchar(chr);
	return(1);
}