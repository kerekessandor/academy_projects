#include "../includes/ft_printf.h"

int		edit_string(va_list *ap, t_flag flag)
{
	char *text;
	char *spaces;

	text = va_arg(*ap, char *);
	if (flag.width > ft_strlen(text))
	{
		spaces = ft_memalloc(flag.width - ft_strlen(text) + 1);
		spaces = ft_memset(spaces, ' ', flag.width - ft_strlen(text));
		if (flag.has_minus == 0)
		{
			ft_putstr(spaces);
			ft_putstr(text);
		}
		else
		{
			ft_putstr(text);
			ft_putstr(spaces);
		}
	}
	else if (!text)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
		ft_putstr(text);
	return (ft_strlen(text));
}